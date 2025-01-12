#include "examshell.h"

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    int status;
    int done = 0;
    pid_t cpid;

    cpid = fork();
    if (cpid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execve(argv[0], argv, envp);
    }
    cpid = fork();
    if (cpid == 0)
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execve(argv[0], argv, envp);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(-1, &status, 0);
    waitpid(-1, &status, 0);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void exec_cmd(int argc, char **argv, char **envp)
{
    int i, num_pipes = argc - 2; // Nombre de pipes nécessaires
    int **fd = malloc(sizeof(int *) * num_pipes); // Tableau pour stocker les pipes
    pid_t pid;

    // Création des pipes
    for (i = 0; i < num_pipes; i++)
    {
        fd[i] = malloc(sizeof(int) * 2);
        if (pipe(fd[i]) == -1)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    // Création des processus
    for (i = 0; i < argc - 1; i++)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) // Processus enfant
        {
            // Si ce n'est pas la première commande, rediriger stdin
            if (i > 0)
            {
                dup2(fd[i - 1][0], STDIN_FILENO);
            }

            // Si ce n'est pas la dernière commande, rediriger stdout
            if (i < argc - 2)
            {
                dup2(fd[i][1], STDOUT_FILENO);
            }

            // Fermeture des pipes inutiles
            for (int j = 0; j < num_pipes; j++)
            {
                close(fd[j][0]);
                close(fd[j][1]);
            }

            // Exécuter la commande
            char *cmd_argv[] = {argv[i + 1], NULL}; // Commande actuelle
            if (execve(cmd_argv[0], cmd_argv, envp) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
    }

    // Fermeture des pipes inutiles dans le parent
    for (i = 0; i < num_pipes; i++)
    {
        close(fd[i][0]);
        close(fd[i][1]);
        free(fd[i]);
    }
    free(fd);

    // Attente de tous les processus enfants
    for (i = 0; i < argc - 1; i++)
    {
        wait(NULL);
    }
}

int main(int argc, char **argv, char **envp)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s cmd1 cmd2 ... cmdN\n", argv[0]);
        return 1;
    }

    exec_cmd(argc, argv, envp);
    return 0;
}

// Fermeture des pipes inutiles
for (int j = 0; j < num_pipes; j++)
{
    // Ne pas fermer les descripteurs utilisés dans dup2
    if (j != i - 1) // Exception pour stdin redirigé
        close(pipes[j][0]);
    if (j != i)     // Exception pour stdout redirigé
        close(pipes[j][1]);
}

// valgrind --track-origins=yes --show-leak-kinds=all --leak-check=full ./microshell
// /bin/echo yes ; /bin/ls -la | /bin/grep "main"