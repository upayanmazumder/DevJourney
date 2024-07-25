var http = require('http');
http.createServer(function(req, res) {
    res.writeHead(200,{'Content-Type': 'text/html'});
    res.end('Hello, world!');
    console.log('Request served!');
}).listen(8080);
console.log('Server listening on port 8080\n >> http://localhost:8080')