#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int id;
	pid_t ppid, pid;

	id = fork();

	//The child process should always terminate first before the parent process
	
	if (id != 0)
	{
		wait(NULL);
	}

	pid = getpid(); //current process identifier
	ppid = getppid();//parent process identifier
	printf("The id returned by fork is : %d\n", id);
	printf("current id: %d, parent id: %d\n", pid, ppid);
	return(0);
}
