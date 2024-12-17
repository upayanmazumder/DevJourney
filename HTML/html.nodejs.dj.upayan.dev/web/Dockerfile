# Use the official Node.js image
FROM node:latest

# Create and change to the app directory
WORKDIR /app

# Copy application dependency manifests to the container image
COPY package*.json ./

# Install dependencies for the root
RUN npm install

# Copy the local code to the container image
WORKDIR /app
COPY . .

EXPOSE 3000

# Run the web service on container startup
CMD ["node","server"]
