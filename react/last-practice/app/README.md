# React + Vite App

This app is built with [Vite](https://vite.dev/) and React. Dependencies are managed with [pnpm](https://pnpm.io/).

## Scripts

Run these from this directory:

| Command        | Description                                   |
| -------------- | --------------------------------------------- |
| `pnpm install` | Install dependencies from `pnpm-lock.yaml`    |
| `pnpm dev`     | Start the dev server on http://localhost:3000 |
| `pnpm build`   | Build for production into `build/`            |
| `pnpm preview` | Serve the production build locally            |
| `pnpm test`    | Run the unit tests with Vitest                |

## Notes

- Vite reads `index.html` from the project root, not from `public/`.
- Only variables prefixed with `VITE_` are exposed to the client.
- `pnpm install --frozen-lockfile` is what CI runs, so commit lockfile changes.
