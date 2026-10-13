#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

#ifndef PORT
#define PORT 8080
#endif

static int send_all(int fd, const char *data, size_t length) {
    size_t sent = 0;
    while (sent < length) {
        ssize_t count = send(fd, data + sent, length - sent, 0);
        if (count < 0 && errno == EINTR)
            continue;
        if (count <= 0)
            return -1;
        sent += (size_t)count;
    }
    return 0;
}

int main(void) {
    signal(SIGPIPE, SIG_IGN);

    int listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener < 0) {
        perror("socket");
        return 1;
    }

    int reuse = 1;
    if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("setsockopt");
        close(listener);
        return 1;
    }

    struct sockaddr_in address = {
        .sin_family = AF_INET, .sin_port = htons(PORT), .sin_addr.s_addr = htonl(INADDR_LOOPBACK)};
    if (bind(listener, (struct sockaddr *)&address, sizeof(address)) < 0 ||
        listen(listener, 5) < 0) {
        perror("bind/listen");
        close(listener);
        return 1;
    }

    printf("Listening on 127.0.0.1:%d\n", PORT);
    fflush(stdout);

    for (;;) {
        int client = accept(listener, NULL, NULL);
        if (client < 0) {
            if (errno == EINTR)
                continue;
            perror("accept");
            close(listener);
            return 1;
        }

        char buffer[4096];
        int logged = 0;
        for (;;) {
            ssize_t count = recv(client, buffer, sizeof(buffer), 0);
            if (count < 0 && errno == EINTR)
                continue;
            if (count < 0) {
                perror("recv");
                break;
            }
            if (count == 0)
                break;
            if (!logged) {
                fputs("Client: ", stdout);
                logged = 1;
            }
            fwrite(buffer, 1, (size_t)count, stdout);
            if (send_all(client, buffer, (size_t)count) < 0) {
                perror("send");
                break;
            }
        }
        if (logged) {
            putchar('\n');
            fflush(stdout);
        }
        close(client);
    }
}
