const express = require('express');
const app = express();
const port = 4000;

app.use((req, res, next) => {
  console.log(`${req.method} ${req.url}`);
  next();
});

app.get('/', (req, res) => {
  res.send('Hello from API!');
});

app.listen(port, () => {
  console.log(`API server running at http://localhost:${port}`);
});