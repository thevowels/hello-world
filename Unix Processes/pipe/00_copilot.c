#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    int **pipefd;
    pid_t *cpid;
    char buf;
    int n;
    int i;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string> <number_of_pipes>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    n = atoi(argv[2]);
    if (n <= 0) {
        fprintf(stderr, "Number of pipes must be positive\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for pipe file descriptors and child PIDs
    pipefd = malloc(n * sizeof(int *));
    cpid = malloc(n * sizeof(pid_t));
    
    for (i = 0; i < n; i++) {
        pipefd[i] = malloc(2 * sizeof(int));
    }

    // Create n pipes
    for (i = 0; i < n; i++) {
        if (pipe(pipefd[i]) == -1) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    // Create n child processes
    for (i = 0; i < n; i++) {
        cpid[i] = fork();
        if (cpid[i] == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (cpid[i] == 0) {    /* Child reads from pipe i */
            // Close all write ends and other read ends
            for (int j = 0; j < n; j++) {
                close(pipefd[j][1]);  // Close write ends
                if (j != i) {
                    close(pipefd[j][0]);  // Close other read ends
                }
            }

            printf("Child %d reading from pipe %d: ", i, i);
            while (read(pipefd[i][0], &buf, 1) > 0)
                write(STDOUT_FILENO, &buf, 1);

            write(STDOUT_FILENO, "\n", 1);
            close(pipefd[i][0]);
            _exit(EXIT_SUCCESS);
        }
    }

    /* Parent writes to all pipes */
    // Close all read ends
    for (i = 0; i < n; i++) {
        close(pipefd[i][0]);
    }

    // Write to all pipes
    for (i = 0; i < n; i++) {
        write(pipefd[i][1], argv[1], strlen(argv[1]));
        close(pipefd[i][1]);  // Close write end so child sees EOF
    }

    // Wait for all children
    for (i = 0; i < n; i++) {
        wait(NULL);
    }

    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(pipefd[i]);
    }
    free(pipefd);
    free(cpid);

    exit(EXIT_SUCCESS);
}