/*
** EPITECH PROJECT, 2019
** main_shell.c
** File description:
** the control function
*/

#include "my.h"
#include <sys/types.h>
#include <signal.h>

int check_segfault(int status, pid_t child)
{
    int signal = WTERMSIG(status);

    if (signal == SIGFPE)
        my_putstr("Floating exception");
    if (signal == SIGSEGV)
        my_putstr("Segmentation fault");
    if (WCOREDUMP(status)) {
        kill(child, SIGSEGV);
        my_putstr(" (core dumped)\n");
        status = 0;
    } else if (signal != 0)
        my_putchar('\n');
    return status;
}

void mini_shell(char **env)
{
    pid_t pid = getpid();
    int status = 0;
    char *command = NULL;

    while (status != 256) {
        if (pid == 0) {
            exec(command, env);
            exit(0);
        } else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else {
            if (builtin(env, &command) == 1) {
                pid = fork();
                waitpid(pid, &status, WIFSIGNALED(status));
                status = check_segfault(status, pid);
            }
        }
    }
    free(command);
}
