const http = require('http');
const fs = require('fs');
const path = require('path');

const ROOT = path.resolve(__dirname);
const hostname = `0.0.0.0`;
const port = 3000;

const server = http.createServer((req, res) => {
    console.log(`Request for ${req.url} received.`);

    let filePath;
    if (req.url === '/' || req.url === '') {
        filePath = path.join(ROOT, 'routes', 'index.html');
    } else if (req.url === '/favicon.ico') {
        filePath = path.join(ROOT, 'public', 'favicon.ico');
    } else if (req.url.startsWith('/fonts')) {
        filePath = path.join(ROOT, 'public', req.url);
    } else if (req.url.startsWith('/media')) {
        filePath = path.join(ROOT, req.url);
    } else if (req.url.startsWith('/styles')) {
        filePath = path.join(ROOT, req.url);
    } else if (req.url.startsWith('/scripts')) {
        filePath = path.join(ROOT, req.url);
    } else if (req.url.startsWith('/components')) {
        filePath = path.join(ROOT, req.url);
    } else if (req.url === '/404.html') {
        filePath = path.join(ROOT, 'routes', '404.html');
    } else {
        filePath = path.join(ROOT, 'routes', req.url);
    }

    filePath = path.normalize(filePath);

    if (!filePath.startsWith(ROOT)) {
        res.writeHead(403);
        res.end('Access denied');
        return;
    }

    if (fs.existsSync(filePath) && fs.lstatSync(filePath).isDirectory()) {
        filePath = path.join(filePath, 'index.html');
    }

    const extname = String(path.extname(filePath)).toLowerCase();
    const mimeTypes = {
        '.html': 'text/html',
        '.js': 'text/javascript',
        '.css': 'text/css',
        '.json': 'application/json',
        '.png': 'image/png',
        '.jpg': 'image/jpg',
        '.gif': 'image/gif',
        '.wav': 'audio/wav',
        '.mp4': 'video/mp4',
        '.woff': 'application/font-woff',
        '.ttf': 'application/font-ttf',
        '.eot': 'application/vnd.ms-fontobject',
        '.otf': 'application/font-otf',
        '.svg': 'application/image/svg+xml'
    };

    const contentType = mimeTypes[extname] || 'application/octet-stream';

    fs.readFile(filePath, (error, content) => {
        if (error) {
            if (error.code === 'ENOENT') {
                fs.readFile(filePath + '.html', (errorHtml, contentHtml) => {
                    if (errorHtml) {
                        if (errorHtml.code === 'ENOENT') {
                            fs.readFile(path.join(ROOT, 'routes', '404.html'), (error404, content404) => {
                                if (error404) {
                                    res.writeHead(500);
                                    res.end('Error loading 404 page');
                                } else {
                                    res.writeHead(404, { 'Content-Type': 'text/html' });
                                    res.end(content404, 'utf-8');
                                }
                            });
                        } else {
                            res.writeHead(500);
                            res.end(`Sorry, check with the site admin for error: ${errorHtml.code} ..\n`);
                        }
                    } else {
                        res.writeHead(200, { 'Content-Type': 'text/html' });
                        res.end(contentHtml, 'utf-8');
                    }
                });
            } else {
                res.writeHead(500);
                res.end(`Sorry, check with the site admin for error: ${error.code} ..\n`);
            }
        } else {
            res.writeHead(200, { 'Content-Type': contentType });
            res.end(content, 'utf-8');
        }
    });
});

server.listen(port, hostname, () => {
    console.log(`Server running at http://localhost:${port}`);
});