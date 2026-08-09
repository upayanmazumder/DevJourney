"use client";

import { useEffect, useState } from "react";
import axios from "@/lib/axios";
import { Button } from "@/components/ui/button";
import {
  Card,
  CardContent,
  CardDescription,
  CardHeader,
  CardTitle,
} from "@/components/ui/card";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from "@/components/ui/select";
import {
  Table,
  TableBody,
  TableCell,
  TableHead,
  TableHeader,
  TableRow,
} from "@/components/ui/table";
import { Badge } from "@/components/ui/badge";
import { Alert, AlertDescription } from "@/components/ui/alert";
import { Separator } from "@/components/ui/separator";

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

function Stat({ label, value }: { label: string; value: React.ReactNode }) {
  return (
    <div className="space-y-1">
      <dt className="text-xs font-medium tracking-wide text-muted-foreground uppercase">
        {label}
      </dt>
      <dd className="text-2xl font-semibold tabular-nums">{value}</dd>
    </div>
  );
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
    <main className="mx-auto flex w-full max-w-5xl flex-col gap-8 px-6 py-10">
      <header className="space-y-1">
        <h1 className="text-2xl font-semibold tracking-tight">
          Fleet Trip &amp; Utilization Tracker
        </h1>
        <p className="text-sm text-muted-foreground">
          Telemetry ingest, trip reconstruction, and utilization for the fleet.
        </p>
      </header>

      <Card>
        <CardHeader>
          <CardTitle>Fleet summary</CardTitle>
          <CardDescription>Aggregated across the whole fleet.</CardDescription>
        </CardHeader>
        <CardContent>
          {summaryError && (
            <Alert variant="destructive">
              <AlertDescription>{summaryError}</AlertDescription>
            </Alert>
          )}
          {!summaryError && !summary && (
            <p className="text-sm text-muted-foreground">Loading…</p>
          )}
          {summary && (
            <dl className="grid grid-cols-2 gap-6 sm:grid-cols-4">
              <Stat label="Vehicles" value={summary.vehicle_count} />
              <Stat label="Total trips" value={summary.total_trips} />
              <Stat label="Total distance (km)" value={summary.total_distance_km} />
              <Stat
                label="Most active"
                value={
                  summary.most_active_vehicle
                    ? `${summary.most_active_vehicle.vehicle_id} (${summary.most_active_vehicle.distance_km} km)`
                    : "—"
                }
              />
            </dl>
          )}
        </CardContent>
      </Card>

      <Card>
        <CardHeader>
          <CardTitle>Vehicle lookup</CardTitle>
          <CardDescription>Trips and utilization for a single vehicle.</CardDescription>
        </CardHeader>
        <CardContent className="space-y-6">
          <div className="flex flex-wrap items-end gap-3">
            <div className="flex flex-col gap-1.5">
              <Label htmlFor="vehicleId">Vehicle ID</Label>
              <Input
                id="vehicleId"
                className="w-32"
                value={vehicleId}
                onChange={(e) => setVehicleId(e.target.value)}
              />
            </div>
            <div className="flex flex-col gap-1.5">
              <Label htmlFor="from">From</Label>
              <Input
                id="from"
                type="datetime-local"
                value={from}
                onChange={(e) => setFrom(e.target.value)}
              />
            </div>
            <div className="flex flex-col gap-1.5">
              <Label htmlFor="to">To</Label>
              <Input
                id="to"
                type="datetime-local"
                value={to}
                onChange={(e) => setTo(e.target.value)}
              />
            </div>
            <Button onClick={fetchTrips} disabled={tripsLoading || !vehicleId}>
              {tripsLoading ? "Loading…" : "Get trips"}
            </Button>
            <Button
              variant="secondary"
              onClick={fetchUtilization}
              disabled={utilizationLoading || !vehicleId}
            >
              {utilizationLoading ? "Loading…" : "Get utilization"}
            </Button>
          </div>

          {tripsError && (
            <Alert variant="destructive">
              <AlertDescription>{tripsError}</AlertDescription>
            </Alert>
          )}
          {trips && (
            <div className="overflow-x-auto rounded-lg border">
              <Table>
                <TableHeader>
                  <TableRow>
                    <TableHead>Start</TableHead>
                    <TableHead>End</TableHead>
                    <TableHead className="text-right">Duration (min)</TableHead>
                    <TableHead className="text-right">Distance (km)</TableHead>
                    <TableHead className="text-right">Avg speed</TableHead>
                    <TableHead className="text-right">Max speed</TableHead>
                  </TableRow>
                </TableHeader>
                <TableBody>
                  {trips.length === 0 && (
                    <TableRow>
                      <TableCell colSpan={6} className="text-center text-muted-foreground">
                        No trips for this vehicle.
                      </TableCell>
                    </TableRow>
                  )}
                  {trips.map((t) => (
                    <TableRow key={t.start_time}>
                      <TableCell className="font-mono text-xs">{t.start_time}</TableCell>
                      <TableCell className="font-mono text-xs">{t.end_time}</TableCell>
                      <TableCell className="text-right tabular-nums">{t.duration_min}</TableCell>
                      <TableCell className="text-right tabular-nums">{t.distance_km}</TableCell>
                      <TableCell className="text-right tabular-nums">{t.avg_speed}</TableCell>
                      <TableCell className="text-right tabular-nums">{t.max_speed}</TableCell>
                    </TableRow>
                  ))}
                </TableBody>
              </Table>
            </div>
          )}

          {utilizationError && (
            <Alert variant="destructive">
              <AlertDescription>{utilizationError}</AlertDescription>
            </Alert>
          )}
          {utilization && (
            <>
              <Separator />
              <dl className="grid grid-cols-3 gap-6">
                <div className="space-y-1">
                  <dt className="text-xs font-medium tracking-wide text-muted-foreground uppercase">
                    Driving
                  </dt>
                  <dd>
                    <Badge className="text-sm">{utilization.driving_pct}%</Badge>
                  </dd>
                </div>
                <div className="space-y-1">
                  <dt className="text-xs font-medium tracking-wide text-muted-foreground uppercase">
                    Idle
                  </dt>
                  <dd>
                    <Badge variant="secondary" className="text-sm">
                      {utilization.idle_pct}%
                    </Badge>
                  </dd>
                </div>
                <div className="space-y-1">
                  <dt className="text-xs font-medium tracking-wide text-muted-foreground uppercase">
                    Off
                  </dt>
                  <dd>
                    <Badge variant="outline" className="text-sm">
                      {utilization.off_pct}%
                    </Badge>
                  </dd>
                </div>
              </dl>
            </>
          )}
        </CardContent>
      </Card>

      <Card>
        <CardHeader>
          <CardTitle>Ingest telemetry</CardTitle>
          <CardDescription>POST a single ping to /telemetry.</CardDescription>
        </CardHeader>
        <CardContent className="space-y-4">
          <div className="flex flex-wrap items-end gap-3">
            <div className="flex flex-col gap-1.5">
              <Label htmlFor="pingVehicleId">Vehicle ID</Label>
              <Input
                id="pingVehicleId"
                className="w-32"
                value={pingVehicleId}
                onChange={(e) => setPingVehicleId(e.target.value)}
              />
            </div>
            <div className="flex flex-col gap-1.5">
              <Label htmlFor="pingTimestamp">Timestamp</Label>
              <Input
                id="pingTimestamp"
                type="datetime-local"
                value={pingTimestamp}
                onChange={(e) => setPingTimestamp(e.target.value)}
              />
            </div>
            <div className="flex flex-col gap-1.5">
              <Label htmlFor="pingLat">Lat</Label>
              <Input
                id="pingLat"
                type="number"
                step="any"
                className="w-28"
                value={pingLat}
                onChange={(e) => setPingLat(e.target.value)}
              />
            </div>
            <div className="flex flex-col gap-1.5">
              <Label htmlFor="pingLon">Lon</Label>
              <Input
                id="pingLon"
                type="number"
                step="any"
                className="w-28"
                value={pingLon}
                onChange={(e) => setPingLon(e.target.value)}
              />
            </div>
            <div className="flex flex-col gap-1.5">
              <Label htmlFor="pingSpeed">Speed (km/h)</Label>
              <Input
                id="pingSpeed"
                type="number"
                step="any"
                min={0}
                className="w-24"
                value={pingSpeed}
                onChange={(e) => setPingSpeed(e.target.value)}
              />
            </div>
            <div className="flex flex-col gap-1.5">
              <Label htmlFor="pingIgnition">Ignition</Label>
              <Select
                value={pingIgnition}
                onValueChange={(v) => setPingIgnition(v as "ON" | "OFF")}
              >
                <SelectTrigger id="pingIgnition" className="w-24">
                  <SelectValue />
                </SelectTrigger>
                <SelectContent>
                  <SelectItem value="ON">ON</SelectItem>
                  <SelectItem value="OFF">OFF</SelectItem>
                </SelectContent>
              </Select>
            </div>
            <Button onClick={submitPing} disabled={ingestLoading}>
              {ingestLoading ? "Sending…" : "POST /telemetry"}
            </Button>
          </div>

          {ingestError && (
            <Alert variant="destructive">
              <AlertDescription>{ingestError}</AlertDescription>
            </Alert>
          )}
          {ingestResult && (
            <div className="space-y-2 text-sm">
              <div className="flex flex-wrap items-center gap-2">
                <Badge variant="outline">received {ingestResult.received}</Badge>
                <Badge>inserted {ingestResult.inserted}</Badge>
                <Badge variant="secondary">duplicates {ingestResult.duplicates}</Badge>
              </div>
              {ingestResult.invalid.length > 0 && (
                <ul className="list-disc space-y-1 pl-5 text-destructive">
                  {ingestResult.invalid.map((v) => (
                    <li key={v.index}>
                      #{v.index}: {v.reason}
                    </li>
                  ))}
                </ul>
              )}
            </div>
          )}
        </CardContent>
      </Card>
    </main>
  );
}
