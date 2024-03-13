
FROM node
# Set the working directory in the container

# Copy package.json and package-lock.json
COPY package*.json ./
# Install project dependencies
RUN npm install
# Copy the application code into the container
COPY . .
# Expose the port on which the application will run
EXPOSE 3000
# Define the command to start the application
CMD [ "node", "app.js" ]



