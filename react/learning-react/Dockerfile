# Stage 1: Build the app
FROM node:latest AS build-app
WORKDIR /app
COPY app/package.json ./package.json
RUN npm install
COPY app/ ./
RUN npm run build

# Stage 2: Prepare the API
FROM node:latest AS build-api
WORKDIR /api
COPY api/package.json ./package.json
RUN npm install
COPY api/ ./

# Stage 3: Run both app and API
FROM node:latest
WORKDIR /app
COPY --from=build-app /app/build ./build
COPY --from=build-app /app/server.js ./server.js
COPY --from=build-app /app/node_modules ./node_modules
COPY --from=build-api /api ./api

# Install serve for serving the React app
RUN npm install -g serve

# Expose ports
EXPOSE 3000 5000

# Start both the app and the API
CMD ["sh", "-c", "node server.js & cd api && npm run server"]