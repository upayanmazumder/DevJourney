#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();
    printf("24BDS0367 Upayan Mazumder\n");

    if (pid == 0) {
        printf("Child process\n");
        printf("Child PID = %d\n", getpid());
        printf("Parent PID = %d\n", getppid());
    } else {
        printf("Parent Process\n");
        printf("Parent PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);
    }

    return 1;
}
