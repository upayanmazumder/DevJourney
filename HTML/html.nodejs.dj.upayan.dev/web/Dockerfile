# Use the official Node.js image
FROM node:latest

# Create and change to the app directory
WORKDIR /app

# Copy package manifests and install dependencies
COPY package*.json ./
RUN npm install

# Copy the local code to the container image
COPY . .

# Expose port 3000 to external traffic
EXPOSE 3000

# Start the Node.js server
CMD ["node", "server.js"]
