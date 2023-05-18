#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid, max_pid;

	pid = getpid();
	max_pid = sysconf(_SC_CHILD_MAX);

	printf("The process id is : %u\n", pid);
	printf("The maximum process id is: %u\n", max_pid);
	return 0;
}
