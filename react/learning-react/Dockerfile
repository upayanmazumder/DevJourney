# Stage 1: Build the app
FROM node:latest AS build-app
WORKDIR /app
# corepack is no longer shipped in Node >= 25; install pnpm directly
RUN npm install -g pnpm@11
COPY app/package.json ./package.json
COPY app/pnpm-lock.yaml ./pnpm-lock.yaml
COPY app/pnpm-workspace.yaml ./pnpm-workspace.yaml
RUN pnpm install --frozen-lockfile
COPY app/ ./
RUN pnpm run build

# Stage 2: Prepare the API
FROM node:latest AS build-api
WORKDIR /api
RUN npm install -g pnpm@11
COPY api/package.json ./package.json
COPY api/pnpm-lock.yaml ./pnpm-lock.yaml
RUN pnpm install --frozen-lockfile --prod
COPY api/ ./

# Stage 3: Run both app and API
FROM node:latest
WORKDIR /app
RUN npm install -g pnpm@11
COPY --from=build-app /app/build ./build
COPY --from=build-app /app/server.js ./server.js
COPY --from=build-app /app/node_modules ./node_modules
COPY --from=build-api /api ./api

    # Install serve for serving the React app (npm's global bin is on PATH)
    RUN npm install -g serve

# Expose ports
EXPOSE 3000 5000

# Start both the app and the API (use pnpm for the api)
CMD ["sh", "-c", "node server.js & cd api && pnpm run server"]
