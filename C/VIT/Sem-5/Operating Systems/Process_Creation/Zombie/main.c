#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();
    printf("24BDS0367 Upayan Mazumder");

    if (pid == 0) {
        printf("Child Process\n");
        printf("Child PID = %d\n", getpid());
        printf("Child exiting...\n");
        exit(0);
    } else {
        printf("Parent Process\n");
        printf("Parent PID = %d\n", getpid());
        sleep(10);

        printf("Parent exiting...\n");
    }
    return 0;
}
