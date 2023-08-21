#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

#define MAX_INPUT_LENGTH 1024

void display_env_vars() {
    extern char **environ;
    char **env;
    for (env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
}

int main() {
    char *input = NULL;
    size_t len = 0;
    ssize_t read_len;

    while (1) {
        printf("#cisfun$ ");
        read_len = getline(&input, &len, stdin);

        if (read_len == -1) {
            if (feof(stdin)) {
                printf("\n");
                break;
            } else {
                perror("getline");
                exit(1);
            }
        }

        if (input[read_len - 1] == '\n') {
            input[read_len - 1] = '\0'; /* Remove the newline character */
        }

        if (strcmp(input, "env") == 0) {
            display_env_vars();
        } else {
            execute_command(input);
        }
    }

    free(input);
    return 0;
}

