#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s \"message\"\n", argv[0]);
        return 1;
    }
    signal(SIGPIPE, SIG_IGN);

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in address = {
        .sin_family = AF_INET, .sin_port = htons(PORT), .sin_addr.s_addr = htonl(INADDR_LOOPBACK)};
    if (connect(fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("connect");
        close(fd);
        return 1;
    }

    if (send_all(fd, argv[1], strlen(argv[1])) < 0 || shutdown(fd, SHUT_WR) < 0) {
        perror("send/shutdown");
        close(fd);
        return 1;
    }

    char buffer[4096];
    for (;;) {
        ssize_t count = recv(fd, buffer, sizeof(buffer), 0);
        if (count < 0 && errno == EINTR)
            continue;
        if (count < 0) {
            perror("recv");
            close(fd);
            return 1;
        }
        if (count == 0)
            break;
        if (fwrite(buffer, 1, (size_t)count, stdout) != (size_t)count) {
            perror("stdout");
            close(fd);
            return 1;
        }
    }
    close(fd);
    if (putchar('\n') == EOF || fflush(stdout) == EOF) {
        perror("stdout");
        return 1;
    }
    return 0;
}
