#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

void execute_command(char *command)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
    }
    else if (pid == 0)
    {
        /* Child process */
        char *args[4];
        args[0] = "sh";
        args[1] = "-c";
        args[2] = command;
        args[3] = NULL;
        execvp("sh", args);
        perror("./shell");
        _exit(1);
    }
    else
    {
        /* Parent process */
        wait(NULL);
    }
}
