# Fleet Trip & Utilization Tracker

Mock 4-hour take-home (Node/Express). No AI/ML, no external maps/geocoding APIs.

## Data model — telemetry ping (input)
```
vehicle_id: string
timestamp: ISO-8601 datetime
lat: float
lon: float
speed_kmph: float
ignition: "ON" | "OFF"
```

## Trip reconstruction rules
- A **trip starts** at the first `ignition=ON` ping after a period of `OFF` (or after no prior data for that vehicle).
- A **trip ends** when either:
  - ignition flips to `OFF`, or
  - the gap between two consecutive pings for that vehicle exceeds **30 minutes** (treat as a dropped-connection trip-close, even if ignition is still ON).
- Pings may arrive **out of order** and may be **duplicated** (same `vehicle_id`+`timestamp`) — dedupe and sort per vehicle before processing.
- A ping with `speed_kmph > 0` but `ignition=OFF` is bad data — decide how to handle it (log/skip/override) and be ready to defend the choice.

## Required endpoints
1. `POST /telemetry` — bulk-accepts an array of pings. Idempotent: re-posting the same ping twice must not duplicate a trip or distort distance.
2. `GET /vehicles/:id/trips` — reconstructed trips: `start_time`, `end_time`, `duration_min`, `distance_km` (haversine between consecutive pings, summed), `avg_speed`, `max_speed`.
3. `GET /vehicles/:id/utilization?from=&to=` — % of the window spent **driving** (in a trip) vs **idle** (ignition ON, speed 0) vs **off**.
4. `GET /fleet/summary` — total trips, total distance, and the single most-active vehicle across the whole fleet.

## Bonus (only after the 4 core endpoints are solid + tested)
- `POST /geofences` (circle: center lat/lon + radius) + flag trips that enter/exit one.
- Idle-alert: ignition ON + speed 0 for > 10 continuous minutes → surface as an alert list.

## Constraints
- No AI/ML, no external geocoding/maps API — pure math (haversine) from lat/lon.
- Persistent store required — no in-memory `Map`/array as the source of truth. SQLite (zero external infra, fastest to stand up live) unless you want Postgres for closer-to-prod practice.
- Node/Express.

## Time box (4h)
- 0:00–0:30 — design: data model, trip state machine, API contract
- 0:30–2:00 — ingest endpoint + trip-detection state machine
- 2:00–3:00 — metrics + utilization + fleet summary endpoints
- 3:00–3:45 — edge cases (dupes, out-of-order, gaps, bad data) + tests
- 3:45–4:00 — buffer

## Grading lens
Correctness of the trip-boundary state machine on messy input; API design sense (idempotency, status codes, pagination if needed); ability to articulate tradeoffs (in-memory vs SQL, haversine vs Euclidean, ingestion scaling).
</content>
<parameter name="i">Write problem brief for fleet tracker exercise