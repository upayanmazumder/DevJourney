import express from "express";
import { ingestPings } from "./ingest.js";
import { reconstructTrips, getPings, getAllVehicleIds } from "./trips.js";
import { computeUtilization } from "./utilization.js";

const app = express();
app.use(express.json());

app.get("/health", (_req, res) => {
  res.json({ status: "ok" });
});

app.post("/telemetry", async (req, res) => {
  const body: unknown = req.body;
  let pings: unknown[] | undefined;
  if (Array.isArray(body)) {
    pings = body;
  } else if (body && typeof body === "object" && "pings" in body && Array.isArray(body.pings)) {
    pings = body.pings;
  }
  if (!pings) {
    res.status(400).json({ error: "body must be an array of pings, or { pings: [...] }" });
    return;
  }
  const result = await ingestPings(pings);
  res.status(202).json(result);
});

app.get("/vehicles/:id/trips", async (req, res) => {
  const vehicleId = req.params.id;
  const trips = reconstructTrips(await getPings(vehicleId));
  res.json({ vehicle_id: vehicleId, trips });
});

app.get("/vehicles/:id/utilization", async (req, res) => {
  const vehicleId = req.params.id;
  const from = Date.parse(String(req.query.from ?? ""));
  const to = Date.parse(String(req.query.to ?? ""));
  if (Number.isNaN(from) || Number.isNaN(to) || to <= from) {
    res.status(400).json({ error: "from and to must be valid ISO dates with to > from" });
    return;
  }
  res.json(await computeUtilization(vehicleId, from, to));
});

app.get("/fleet/summary", async (_req, res) => {
  const vehicleIds = await getAllVehicleIds();
  let totalTrips = 0;
  let totalDistanceKm = 0;
  let mostActive: { vehicle_id: string; distance_km: number } | null = null;

  for (const vehicleId of vehicleIds) {
    const trips = reconstructTrips(await getPings(vehicleId));
    const distanceKm = trips.reduce((sum, t) => sum + t.distance_km, 0);
    totalTrips += trips.length;
    totalDistanceKm += distanceKm;
    if (!mostActive || distanceKm > mostActive.distance_km) {
      mostActive = { vehicle_id: vehicleId, distance_km: Number(distanceKm.toFixed(3)) };
    }
  }

  res.json({
    vehicle_count: vehicleIds.length,
    total_trips: totalTrips,
    total_distance_km: Number(totalDistanceKm.toFixed(3)),
    most_active_vehicle: mostActive,
  });
});

export default app;