const express = require('express');
const fs = require('fs');
const path = require('path');
const app = express();
const port = 3000;

// Serve static files from the 'public' directory
app.use(express.static(path.join(__dirname, 'public')));

// Serve index.html for the home page
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'routes', 'index.html'));
});

// Dynamically serve other HTML files from the 'routes' directory
app.get('/:page', (req, res) => {
    const page = req.params.page;
    const filePath = path.join(__dirname, 'routes', `${page}.html`);
    
    fs.access(filePath, fs.constants.F_OK, (err) => {
        if (err) {
            res.status(404).send('Page not found');
        } else {
            res.sendFile(filePath);
        }
    });
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});

//Testing