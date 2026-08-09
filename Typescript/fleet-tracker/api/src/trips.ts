import { db } from "./db.js";
import { haversineKm } from "./geo.js";

export interface Ping {
  vehicle_id: string;
  timestamp: string;
  lat: number;
  lon: number;
  speed_kmph: number;
  ignition: "ON" | "OFF";
}

export interface Trip {
  vehicle_id: string;
  start_time: string;
  end_time: string;
  duration_min: number;
  distance_km: number;
  avg_speed: number;
  max_speed: number;
}

// Gap between consecutive pings on the same vehicle beyond which we
// force-close a trip, even if ignition never reported OFF (dropped uplink).
export const GAP_CLOSE_MS = 30 * 60 * 1000;

export function getPings(vehicleId: string): Ping[] {
  return db
    .prepare(
      `SELECT vehicle_id, timestamp, lat, lon, speed_kmph, ignition
       FROM pings WHERE vehicle_id = ? ORDER BY timestamp ASC`
    )
    .all(vehicleId) as Ping[];
}

export function getAllVehicleIds(): string[] {
  const rows = db.prepare(`SELECT DISTINCT vehicle_id FROM pings`).all() as {
    vehicle_id: string;
  }[];
  return rows.map((r) => r.vehicle_id);
}

function buildTrip(segment: Ping[]): Trip {
  const start = segment[0]!;
  const end = segment[segment.length - 1]!;

  let distanceKm = 0;
  let maxSpeed = 0;
  let speedSum = 0;
  for (let i = 0; i < segment.length; i++) {
    const p = segment[i]!;
    speedSum += p.speed_kmph;
    maxSpeed = Math.max(maxSpeed, p.speed_kmph);
    if (i > 0) {
      const prev = segment[i - 1]!;
      distanceKm += haversineKm(prev.lat, prev.lon, p.lat, p.lon);
    }
  }

  const durationMin =
    (new Date(end.timestamp).getTime() - new Date(start.timestamp).getTime()) /
    60000;

  return {
    vehicle_id: start.vehicle_id,
    start_time: start.timestamp,
    end_time: end.timestamp,
    duration_min: Number(durationMin.toFixed(2)),
    distance_km: Number(distanceKm.toFixed(3)),
    avg_speed: Number((speedSum / segment.length).toFixed(2)),
    max_speed: maxSpeed,
  };
}

/**
 * Reconstruct trips from a chronologically sorted, deduped ping list.
 * A trip is a maximal run of ignition=ON pings with no gap exceeding
 * GAP_CLOSE_MS. Pings expects already-sorted input (see getPings).
 */
export function reconstructTrips(pings: Ping[]): Trip[] {
  const trips: Trip[] = [];
  let current: Ping[] = [];

  const flush = () => {
    if (current.length > 0) trips.push(buildTrip(current));
    current = [];
  };

  for (const p of pings) {
    if (p.ignition === "OFF") {
      flush();
      continue;
    }
    if (current.length === 0) {
      current = [p];
      continue;
    }
    const prev = current[current.length - 1]!;
    const gapMs = new Date(p.timestamp).getTime() - new Date(prev.timestamp).getTime();
    if (gapMs > GAP_CLOSE_MS) {
      flush();
      current = [p];
    } else {
      current.push(p);
    }
  }
  flush();

  return trips;
}
