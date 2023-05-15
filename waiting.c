#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int id, n, i;
    id = fork();

    if (id == 0)
    {
        n = 1;
    }
    else
    {
        n = 6;
    }

    if (id != 0)
    {
        //waiting for the child process to finish before the main function starts
        wait(NULL);
    }

    for (i = n; i < (n + 5); i++)
    {
        printf("%d ", i);
        fflush(stdout);
    }
    printf("\n"); 
    return (0);
}