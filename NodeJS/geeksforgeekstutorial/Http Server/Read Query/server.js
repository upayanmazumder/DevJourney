var http = require('http');
var escape = require('escape-html');
http.createServer(function (req, res) {
  res.writeHead(200, {'Content-Type': 'text/html'});
  res.write(escape(req.url));
  res.end();
}).listen(8080);

/* Visit http://localhost:8080/hellothere */