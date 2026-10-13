# TCP Echo Server and Client

The server listens on `127.0.0.1:8080` and returns each message unchanged.

1. Compile both programs:
   ```sh
   cc -std=c11 -Wall -Wextra -o server server.c
   cc -std=c11 -Wall -Wextra -o client client.c
   ```
2. Start the server in one terminal:
   ```sh
   ./server
   ```
3. Run the client in another terminal:
   ```sh
   ./client "Hello, TCP!"
   ```

The client prints `Hello, TCP!`. The server prints `Client: Hello, TCP!`.
Press Ctrl+C to stop the server.
