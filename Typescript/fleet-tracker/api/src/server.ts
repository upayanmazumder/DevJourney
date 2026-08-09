import app from "./app.js";
import { connectDb } from "./db.js";

const PORT = 8000;

async function main(): Promise<void> {
  await connectDb();
  app.listen(PORT, () => {
    console.log(`App is running on port ${PORT}`);
  });
}

main().catch((err: unknown) => {
  console.error("Failed to start server:", err);
  process.exit(1);
});
