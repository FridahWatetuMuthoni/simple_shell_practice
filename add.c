#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int a, b, sum;
	pid_t pid, ppid;

	a = 5;
	b = 10;
	sum = a + b;

	printf("The sum is: %d\n", sum);

	pid = getpid();
	ppid = getppid();

	printf("The current process id : %d\n", pid);
	printf("The parent id is: %d\n", ppid);

	return (0);
}
