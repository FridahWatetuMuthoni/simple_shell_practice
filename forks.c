#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int id;

    id = fork();
    // id = 0 is for the new created process->the child process
    // id = number is for the main process
    printf("ID: %d\n", id);

    if (id == 0)
    {
        printf("We are in the child process\n");
    }
    else
    {
        printf("We are in the main process\n");
    }

    //creating three processes
    if (id != 0)
    {
        fork();
    }

    printf("Hello World\n");
    return (0);
}