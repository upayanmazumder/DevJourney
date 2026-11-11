# Use the official Node.js image
FROM node:latest

# Create and change to the app directory
WORKDIR /app

# corepack is no longer shipped in Node >= 25; install pnpm directly
RUN npm install -g pnpm@11

# Copy package manifests and install dependencies
COPY package.json pnpm-lock.yaml pnpm-workspace.yaml ./
RUN pnpm install --frozen-lockfile

# Copy the local code to the container image
COPY . .

# Expose port 3000 to external traffic
EXPOSE 3000

# Start the Node.js server
CMD ["node", "server.js"]
