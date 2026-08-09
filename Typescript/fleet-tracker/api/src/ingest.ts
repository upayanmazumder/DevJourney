import { db } from "./db.js";
import type { Ping } from "./trips.js";

export interface IngestResult {
  received: number;
  inserted: number;
  duplicates: number;
  invalid: { index: number; reason: string }[];
}

function validatePing(raw: unknown, index: number): { ping: Ping } | { error: string } {
  if (typeof raw !== "object" || raw === null) {
    return { error: `ping[${index}] must be an object` };
  }
  const p = raw as Record<string, unknown>;

  if (typeof p.vehicle_id !== "string" || p.vehicle_id.length === 0) {
    return { error: `ping[${index}].vehicle_id must be a non-empty string` };
  }
  if (typeof p.timestamp !== "string" || Number.isNaN(Date.parse(p.timestamp))) {
    return { error: `ping[${index}].timestamp must be a valid ISO-8601 string` };
  }
  if (typeof p.lat !== "number" || p.lat < -90 || p.lat > 90) {
    return { error: `ping[${index}].lat must be a number in [-90, 90]` };
  }
  if (typeof p.lon !== "number" || p.lon < -180 || p.lon > 180) {
    return { error: `ping[${index}].lon must be a number in [-180, 180]` };
  }
  if (typeof p.speed_kmph !== "number" || p.speed_kmph < 0) {
    return { error: `ping[${index}].speed_kmph must be a non-negative number` };
  }
  if (p.ignition !== "ON" && p.ignition !== "OFF") {
    return { error: `ping[${index}].ignition must be "ON" or "OFF"` };
  }

  return {
    ping: {
      vehicle_id: p.vehicle_id,
      timestamp: new Date(p.timestamp).toISOString(),
      lat: p.lat,
      lon: p.lon,
      speed_kmph: p.speed_kmph,
      ignition: p.ignition,
    },
  };
}

const insertStmt = db.prepare(`
  INSERT OR IGNORE INTO pings (vehicle_id, timestamp, lat, lon, speed_kmph, ignition)
  VALUES (@vehicle_id, @timestamp, @lat, @lon, @speed_kmph, @ignition)
`);

/**
 * Bulk-insert pings. Idempotent: the (vehicle_id, timestamp) primary key
 * makes re-posting the same ping a no-op (counted as a duplicate, not an error).
 * Bad-data guard (speed>0 while ignition=OFF) is accepted as-is: trip
 * reconstruction ignores speed on OFF pings, so it can't distort a trip.
 */
export function ingestPings(rawPings: unknown[]): IngestResult {
  const result: IngestResult = {
    received: rawPings.length,
    inserted: 0,
    duplicates: 0,
    invalid: [],
  };

  const insertMany = db.transaction((pings: Ping[]) => {
    for (const ping of pings) {
      const info = insertStmt.run(ping);
      if (info.changes > 0) result.inserted++;
      else result.duplicates++;
    }
  });

  const validPings: Ping[] = [];
  rawPings.forEach((raw, index) => {
    const outcome = validatePing(raw, index);
    if ("error" in outcome) {
      result.invalid.push({ index, reason: outcome.error });
    } else {
      validPings.push(outcome.ping);
    }
  });

  insertMany(validPings);
  return result;
}

