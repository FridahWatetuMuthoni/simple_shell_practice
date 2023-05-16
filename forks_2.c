#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;

	printf("Before i fork i was one\n");

	pid = fork();

	if (pid == -1)
	{
		perror("Unsuccessfull\n");
	}

	if (pid == 0)
	{
		printf("The child process\n");
	}
	else
	{
		printf("The parent process\n");
	}

	printf("After fork i am two\n");

	return (0);
}
