const express = require('express');
const app = express();
const port = 3001;

app.get('/', (req, res) => {
  res.send('Hello from API!');
});

app.listen(port, () => {
  console.log(`API server running at http://localhost:${port}`);
});