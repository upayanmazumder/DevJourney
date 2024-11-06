# Use the official Node.js image
FROM node

# Create and change to the app directory
WORKDIR /app

# Copy application dependency manifests to the container image
COPY package*.json ./

# Install dependencies 
WORKDIR /app
RUN npm install

# Copy the local code to the container image
WORKDIR /app
COPY . .

# Run the web service on container startup
CMD ["node", "server"]
