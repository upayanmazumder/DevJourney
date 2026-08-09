import "dotenv/config";
import { MongoClient, type Collection } from "mongodb";
import type { Ping } from "./trips.js";

const uri = process.env.MONGODB_URI;
if (!uri) {
  throw new Error("MONGODB_URI is not set (see api/.env)");
}

const dbName = process.env.MONGODB_DB ?? "fleet_tracker";

export const client = new MongoClient(uri);
export const pings: Collection<Ping> = client.db(dbName).collection<Ping>("pings");

let indexesReady: Promise<unknown> | null = null;

/** (vehicle_id, timestamp) uniquely identifies a ping — enforces ingest
 * idempotency and doubles as the sort/range index used by trips + utilization. */
function ensureIndexes(): Promise<unknown> {
  if (!indexesReady) {
    indexesReady = pings.createIndex({ vehicle_id: 1, timestamp: 1 }, { unique: true });
  }
  return indexesReady;
}

export async function connectDb(): Promise<void> {
  await client.connect();
  await ensureIndexes();
}

export async function disconnectDb(): Promise<void> {
  await client.close();
}
