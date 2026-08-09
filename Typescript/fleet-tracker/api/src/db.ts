import Database from "better-sqlite3";

export const db = new Database(process.env.DB_PATH ?? "fleet.db");
db.pragma("journal_mode = WAL");

db.exec(`
  CREATE TABLE IF NOT EXISTS pings (
    vehicle_id  TEXT NOT NULL,
    timestamp   TEXT NOT NULL,
    lat         REAL NOT NULL,
    lon         REAL NOT NULL,
    speed_kmph  REAL NOT NULL,
    ignition    TEXT NOT NULL CHECK (ignition IN ('ON', 'OFF')),
    PRIMARY KEY (vehicle_id, timestamp)
  );

  CREATE INDEX IF NOT EXISTS idx_pings_vehicle_ts ON pings (vehicle_id, timestamp);
`);
