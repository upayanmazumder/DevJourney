import { pings as pingsCollection } from "./db.js";
import type { Ping } from "./trips.js";
import { GAP_CLOSE_MS } from "./trips.js";

export interface Utilization {
  vehicle_id: string;
  from: string;
  to: string;
  driving_pct: number;
  idle_pct: number;
  off_pct: number;
}

type State = "driving" | "idle" | "off";

function stateOf(p: Ping): State {
  if (p.ignition === "OFF") return "off";
  return p.speed_kmph > 0 ? "driving" : "idle";
}

/**
 * % of [from, to] spent driving / idle / off for a vehicle.
 * Time with no ping coverage (before the first ping, after the last, or
 * across a >30min gap) is attributed to "off" — no data is treated the
 * same as a dropped/parked vehicle, matching the trip gap-close rule.
 */
export async function computeUtilization(
  vehicleId: string,
  fromMs: number,
  toMs: number
): Promise<Utilization> {
  const pings = await pingsCollection
    .find({
      vehicle_id: vehicleId,
      timestamp: { $gte: new Date(fromMs).toISOString(), $lte: new Date(toMs).toISOString() },
    })
    .sort({ timestamp: 1 })
    .toArray();

  const totals: Record<State, number> = { driving: 0, idle: 0, off: 0 };
  const windowMs = toMs - fromMs;

  // Attribute each inter-ping interval to the state at its start; any
  // pre-first/post-last/gap>30min span is "off" (no data).
  let cursorMs = fromMs;
  for (let i = 0; i < pings.length; i++) {
    const p = pings[i]!;
    const pMs = new Date(p.timestamp).getTime();
    const gapMs = pMs - cursorMs;
    if (i === 0) {
      totals.off += gapMs; // no coverage before the first ping in window
    } else if (gapMs > GAP_CLOSE_MS) {
      totals.off += gapMs; // dropped-connection gap
    } else {
      totals[stateOf(pings[i - 1]!)] += gapMs;
    }
    cursorMs = pMs;
  }
  if (pings.length > 0) {
    totals.off += toMs - cursorMs; // no coverage after the last ping in window
  } else {
    totals.off = windowMs;
  }

  const pct = (ms: number) => (windowMs > 0 ? Number(((ms / windowMs) * 100).toFixed(2)) : 0);

  return {
    vehicle_id: vehicleId,
    from: new Date(fromMs).toISOString(),
    to: new Date(toMs).toISOString(),
    driving_pct: pct(totals.driving),
    idle_pct: pct(totals.idle),
    off_pct: pct(totals.off),
  };
}