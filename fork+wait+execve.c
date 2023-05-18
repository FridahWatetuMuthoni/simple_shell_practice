#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

void directories(char *args[])
{
	int exec = execve(args[0], args, NULL);
	if(exec == -1)
	{
		perror("Error happened when calling the exec function");
	}
}

int main(int argc, char *argv[])
{
	pid_t pid;
	int i, status;
	char *args[] = {"/bin/ls", "-l", NULL};

	for(i = 0; i < 5; i++)
	{
		pid = fork();
		if(pid == -1)
		{
			perror("Unsuccessfull");
			return(-1);
		}
		if(pid == 0)
		{
			directories(args);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}

	return(0);
}
