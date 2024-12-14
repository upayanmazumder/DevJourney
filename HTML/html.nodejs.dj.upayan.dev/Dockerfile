# Use the official Node.js image
FROM node:23

# Create and change to the app directory
WORKDIR /app

# Copy application dependency manifests to the container image
COPY package*.json ./
COPY api/package*.json ./api/
COPY web/package*.json ./web/

# Install dependencies for the root
RUN npm install

# Install dependencies for the api folder
WORKDIR /app/api
RUN npm install

# Install dependencies for the web folder 
WORKDIR /app/web
RUN npm install

# Copy the local code to the container image
WORKDIR /app
COPY . .

# Expose port 3000 & 4000
EXPOSE 3000
EXPOSE 4000

# Run the web service on container startup
CMD ["sh", "-c", "npm run deploy"]
