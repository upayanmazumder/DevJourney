#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        printf("Child process\n");
        printf("PPID before parent exits = %d\n", getppid());

        sleep(5);

        printf("PPID after parent exits = %d\n", getppid());
    } else {
        printf("Parent process\n");
        printf("Parent PID = %d\n", getpid());

        sleep(2);
        printf("Parent exiting...\n");
        exit(0);
    }
    return 0;
}
