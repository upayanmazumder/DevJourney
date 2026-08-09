import axios from "axios";

// Requests go through the Next.js rewrite in next.config.ts (/api/:path*),
// which proxies to BACKEND_URL server-side. Keeps the backend URL out of
// client bundles and sidesteps CORS entirely.
const instance = axios.create({
  baseURL: "/api",
  headers: {
    "Content-Type": "application/json",
  },
});

export default instance;
