#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	size_t buffer_size = 0;
	char *buffer = NULL;
	pid_t pid;
	char *args[] = {"/bin/ls", buffer, NULL};

	printf("#cisfun$");
	getline(&buffer, &buffer_size, stdin);
	pid = fork();
	if(pid == -1)
	{
		perror("unsuccessful");
		return(-1);
	}
	if(pid == 0)
	{
		int exec_value = execve(args[0], args, NULL);
		if(exec_value == -1)
		{
			perror("Error happened when calling the execve function\n");
		}
	}
	else
	{
		wait(NULL);
		printf("Done with the execution\n");
	}
	free(buffer);
	return(0);
}
