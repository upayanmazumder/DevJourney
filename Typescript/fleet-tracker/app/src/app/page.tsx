"use client";

import { useEffect, useState } from "react";
import axios from "@/lib/axios";

interface Trip {
  vehicle_id: string;
  start_time: string;
  end_time: string;
  duration_min: number;
  distance_km: number;
  avg_speed: number;
  max_speed: number;
}

interface Utilization {
  vehicle_id: string;
  from: string;
  to: string;
  driving_pct: number;
  idle_pct: number;
  off_pct: number;
}

interface FleetSummary {
  vehicle_count: number;
  total_trips: number;
  total_distance_km: number;
  most_active_vehicle: { vehicle_id: string; distance_km: number } | null;
}

interface IngestResult {
  received: number;
  inserted: number;
  duplicates: number;
  invalid: { index: number; reason: string }[];
}


export default function Home() {
  const [summary, setSummary] = useState<FleetSummary | null>(null);
  const [summaryError, setSummaryError] = useState<string | null>(null);

  const [vehicleId, setVehicleId] = useState("V1");
  const [from, setFrom] = useState("");
  const [to, setTo] = useState("");

  const [trips, setTrips] = useState<Trip[] | null>(null);
  const [tripsError, setTripsError] = useState<string | null>(null);
  const [tripsLoading, setTripsLoading] = useState(false);

  const [utilization, setUtilization] = useState<Utilization | null>(null);
  const [utilizationError, setUtilizationError] = useState<string | null>(null);
  const [utilizationLoading, setUtilizationLoading] = useState(false);

  const [pingVehicleId, setPingVehicleId] = useState("V1");
  const [pingTimestamp, setPingTimestamp] = useState("");
  const [pingLat, setPingLat] = useState("12.9716");
  const [pingLon, setPingLon] = useState("77.5946");
  const [pingSpeed, setPingSpeed] = useState("0");
  const [pingIgnition, setPingIgnition] = useState<"ON" | "OFF">("ON");
  const [ingestResult, setIngestResult] = useState<IngestResult | null>(null);
  const [ingestError, setIngestError] = useState<string | null>(null);
  const [ingestLoading, setIngestLoading] = useState(false);

  const loadSummary = () => {
    axios
      .get<FleetSummary>("/fleet/summary")
      .then((res) => {
        setSummary(res.data);
        setSummaryError(null);
      })
      .catch((err) => setSummaryError(err.message));
  };

  useEffect(() => {
    loadSummary();
  }, []);

  const fetchTrips = () => {
    if (!vehicleId) return;
    setTripsLoading(true);
    setTripsError(null);
    axios
      .get<{ vehicle_id: string; trips: Trip[] }>(`/vehicles/${encodeURIComponent(vehicleId)}/trips`)
      .then((res) => setTrips(res.data.trips))
      .catch((err) => setTripsError(err.response?.data?.error ?? err.message))
      .finally(() => setTripsLoading(false));
  };

  const fetchUtilization = () => {
    if (!vehicleId || !from || !to) {
      setUtilizationError("vehicle, from and to are required");
      return;
    }
    setUtilizationLoading(true);
    setUtilizationError(null);
    axios
      .get<Utilization>(`/vehicles/${encodeURIComponent(vehicleId)}/utilization`, {
        params: {
          from: new Date(from).toISOString(),
          to: new Date(to).toISOString(),
        },
      })
      .then((res) => setUtilization(res.data))
      .catch((err) => setUtilizationError(err.response?.data?.error ?? err.message))
      .finally(() => setUtilizationLoading(false));
  };

  const submitPing = () => {
    if (!pingVehicleId || !pingTimestamp) {
      setIngestError("vehicle id and timestamp are required");
      return;
    }
    const lat = Number(pingLat);
    const lon = Number(pingLon);
    const speed_kmph = Number(pingSpeed);
    if (Number.isNaN(lat) || Number.isNaN(lon) || Number.isNaN(speed_kmph)) {
      setIngestError("lat, lon and speed must be numbers");
      return;
    }
    setIngestLoading(true);
    setIngestError(null);
    axios
      .post<IngestResult>("/telemetry", [
        {
          vehicle_id: pingVehicleId,
          timestamp: new Date(pingTimestamp).toISOString(),
          lat,
          lon,
          speed_kmph,
          ignition: pingIgnition,
        },
      ])
      .then((res) => {
        setIngestResult(res.data);
        loadSummary();
      })
      .catch((err) => setIngestError(err.response?.data?.error ?? err.message))
      .finally(() => setIngestLoading(false));
  };

  return (
    <main className="mx-auto flex w-full max-w-4xl flex-col gap-8 px-6 py-10">
      <header>
        <h1 className="text-2xl font-semibold">Fleet Trip &amp; Utilization Tracker</h1>
        <p className="text-sm text-gray-500">Telemetry ingest, trip reconstruction, and utilization for the fleet.</p>
      </header>

      <section className="rounded-lg border border-gray-200 p-4 dark:border-gray-700">
        <h2 className="mb-3 text-lg font-medium">Fleet summary</h2>
        {summaryError && <p className="text-sm text-red-600">{summaryError}</p>}
        {!summaryError && !summary && <p className="text-sm text-gray-500">Loading…</p>}
        {summary && (
          <dl className="grid grid-cols-2 gap-3 sm:grid-cols-4">
            <div>
              <dt className="text-xs uppercase text-gray-500">Vehicles</dt>
              <dd className="text-xl font-semibold">{summary.vehicle_count}</dd>
            </div>
            <div>
              <dt className="text-xs uppercase text-gray-500">Total trips</dt>
              <dd className="text-xl font-semibold">{summary.total_trips}</dd>
            </div>
            <div>
              <dt className="text-xs uppercase text-gray-500">Total distance (km)</dt>
              <dd className="text-xl font-semibold">{summary.total_distance_km}</dd>
            </div>
            <div>
              <dt className="text-xs uppercase text-gray-500">Most active</dt>
              <dd className="text-xl font-semibold">
                {summary.most_active_vehicle
                  ? `${summary.most_active_vehicle.vehicle_id} (${summary.most_active_vehicle.distance_km} km)`
                  : "—"}
              </dd>
            </div>
          </dl>
        )}
      </section>

      <section className="rounded-lg border border-gray-200 p-4 dark:border-gray-700">
        <h2 className="mb-3 text-lg font-medium">Vehicle lookup</h2>
        <div className="flex flex-wrap items-end gap-3">
          <label className="flex flex-col text-sm">
            Vehicle ID
            <input
              className="rounded border border-gray-300 px-2 py-1 dark:border-gray-600 dark:bg-transparent"
              value={vehicleId}
              onChange={(e) => setVehicleId(e.target.value)}
            />
          </label>
          <label className="flex flex-col text-sm">
            From
            <input
              type="datetime-local"
              className="rounded border border-gray-300 px-2 py-1 dark:border-gray-600 dark:bg-transparent"
              value={from}
              onChange={(e) => setFrom(e.target.value)}
            />
          </label>
          <label className="flex flex-col text-sm">
            To
            <input
              type="datetime-local"
              className="rounded border border-gray-300 px-2 py-1 dark:border-gray-600 dark:bg-transparent"
              value={to}
              onChange={(e) => setTo(e.target.value)}
            />
          </label>
          <button
            className="rounded bg-blue-700 px-3 py-1.5 text-sm font-medium text-white disabled:opacity-50"
            onClick={fetchTrips}
            disabled={tripsLoading || !vehicleId}
          >
            {tripsLoading ? "Loading…" : "Get trips"}
          </button>
          <button
            className="rounded bg-blue-700 px-3 py-1.5 text-sm font-medium text-white disabled:opacity-50"
            onClick={fetchUtilization}
            disabled={utilizationLoading || !vehicleId}
          >
            {utilizationLoading ? "Loading…" : "Get utilization"}
          </button>
        </div>

        {tripsError && <p className="mt-3 text-sm text-red-600">{tripsError}</p>}
        {trips && (
          <div className="mt-4 overflow-x-auto">
            <table className="w-full text-left text-sm">
              <thead>
                <tr className="border-b border-gray-300 dark:border-gray-600">
                  <th className="py-1 pr-3">Start</th>
                  <th className="py-1 pr-3">End</th>
                  <th className="py-1 pr-3">Duration (min)</th>
                  <th className="py-1 pr-3">Distance (km)</th>
                  <th className="py-1 pr-3">Avg speed</th>
                  <th className="py-1 pr-3">Max speed</th>
                </tr>
              </thead>
              <tbody>
                {trips.length === 0 && (
                  <tr>
                    <td className="py-2 text-gray-500" colSpan={6}>
                      No trips for this vehicle.
                    </td>
                  </tr>
                )}
                {trips.map((t) => (
                  <tr key={t.start_time} className="border-b border-gray-100 dark:border-gray-800">
                    <td className="py-1 pr-3">{t.start_time}</td>
                    <td className="py-1 pr-3">{t.end_time}</td>
                    <td className="py-1 pr-3">{t.duration_min}</td>
                    <td className="py-1 pr-3">{t.distance_km}</td>
                    <td className="py-1 pr-3">{t.avg_speed}</td>
                    <td className="py-1 pr-3">{t.max_speed}</td>
                  </tr>
                ))}
              </tbody>
            </table>
          </div>
        )}

        {utilizationError && <p className="mt-3 text-sm text-red-600">{utilizationError}</p>}
        {utilization && (
          <dl className="mt-4 grid grid-cols-3 gap-3">
            <div>
              <dt className="text-xs uppercase text-gray-500">Driving</dt>
              <dd className="text-lg font-semibold">{utilization.driving_pct}%</dd>
            </div>
            <div>
              <dt className="text-xs uppercase text-gray-500">Idle</dt>
              <dd className="text-lg font-semibold">{utilization.idle_pct}%</dd>
            </div>
            <div>
              <dt className="text-xs uppercase text-gray-500">Off</dt>
              <dd className="text-lg font-semibold">{utilization.off_pct}%</dd>
            </div>
          </dl>
        )}
      </section>

      <section className="rounded-lg border border-gray-200 p-4 dark:border-gray-700">
        <h2 className="mb-3 text-lg font-medium">Ingest telemetry</h2>
        <div className="flex flex-wrap items-end gap-3">
          <label className="flex flex-col text-sm">
            Vehicle ID
            <input
              className="rounded border border-gray-300 px-2 py-1 dark:border-gray-600 dark:bg-transparent"
              value={pingVehicleId}
              onChange={(e) => setPingVehicleId(e.target.value)}
            />
          </label>
          <label className="flex flex-col text-sm">
            Timestamp
            <input
              type="datetime-local"
              className="rounded border border-gray-300 px-2 py-1 dark:border-gray-600 dark:bg-transparent"
              value={pingTimestamp}
              onChange={(e) => setPingTimestamp(e.target.value)}
            />
          </label>
          <label className="flex flex-col text-sm">
            Lat
            <input
              type="number"
              step="any"
              className="w-28 rounded border border-gray-300 px-2 py-1 dark:border-gray-600 dark:bg-transparent"
              value={pingLat}
              onChange={(e) => setPingLat(e.target.value)}
            />
          </label>
          <label className="flex flex-col text-sm">
            Lon
            <input
              type="number"
              step="any"
              className="w-28 rounded border border-gray-300 px-2 py-1 dark:border-gray-600 dark:bg-transparent"
              value={pingLon}
              onChange={(e) => setPingLon(e.target.value)}
            />
          </label>
          <label className="flex flex-col text-sm">
            Speed (km/h)
            <input
              type="number"
              step="any"
              min={0}
              className="w-24 rounded border border-gray-300 px-2 py-1 dark:border-gray-600 dark:bg-transparent"
              value={pingSpeed}
              onChange={(e) => setPingSpeed(e.target.value)}
            />
          </label>
          <label className="flex flex-col text-sm">
            Ignition
            <select
              className="rounded border border-gray-300 px-2 py-1 dark:border-gray-600 dark:bg-transparent"
              value={pingIgnition}
              onChange={(e) => setPingIgnition(e.target.value as "ON" | "OFF")}
            >
              <option value="ON">ON</option>
              <option value="OFF">OFF</option>
            </select>
          </label>
          <button
            className="rounded bg-green-700 px-3 py-1.5 text-sm font-medium text-white disabled:opacity-50"
            onClick={submitPing}
            disabled={ingestLoading}
          >
            {ingestLoading ? "Sending…" : "POST /telemetry"}
          </button>
        </div>
        {ingestError && <p className="mt-3 text-sm text-red-600">{ingestError}</p>}
        {ingestResult && (
          <div className="mt-3 text-sm">
            <p>
              received {ingestResult.received}, inserted {ingestResult.inserted}, duplicates{" "}
              {ingestResult.duplicates}
            </p>
            {ingestResult.invalid.length > 0 && (
              <ul className="mt-2 list-disc pl-5 text-red-600">
                {ingestResult.invalid.map((v) => (
                  <li key={v.index}>
                    #{v.index}: {v.reason}
                  </li>
                ))}
              </ul>
            )}
          </div>
        )}
      </section>
    </main>
  );
}
