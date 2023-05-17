#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	
	char *argv[] = {"/bin/ls", "-l", NULL};

	pid = fork();

	if(pid == -1)
	{
		perror("child process creation unsuccessful");
		return(-1);
	}

	if(pid == 0)
	{
		int exec_val = execve(argv[0], argv, NULL);
		if(exec_val == -1)
		{
			perror("Error happened when calling the execve function\n");
		}
	}
	else
	{
		wait(NULL);
		printf("Done with the execution\n");
	}
	return(0);
}
