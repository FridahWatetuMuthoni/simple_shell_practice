#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;

	pid = fork();

	if(pid == -1)
	{
		perror("Unsuccessfull\n");
		return (-1);
	}
	if(pid == 0)
	{
		printf("This is the child process\n");
	}
	else
	{
		wait(NULL);
		printf("This is the parent process\n");
	}

	return (0);
}
