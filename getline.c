#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	size_t n = 10;
	//char *buffer = malloc(sizeof(char) * n);
	char *buffer = NULL;

	printf("Enter name: ");
	getline(&buffer, &n, stdin);
	printf("Name is %sand the buffer size is %ld\n", buffer, n);
	free(buffer);
	return(0);
}
