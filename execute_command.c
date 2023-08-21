#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

#define MAX_INPUT_LENGTH 1024

void execute_command(char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
    } else if (pid == 0) {
        /* Child process */
        char *args[2];
        args[0] = command;
        args[1] = NULL;
        execve(command, args, NULL);
        perror("./shell");
        _exit(1);
    } else {
        /* Parent process */
        wait(NULL);
    }
}
