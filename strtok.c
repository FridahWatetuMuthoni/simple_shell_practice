#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
	char *src = "Writing My own shell";
	char *dest = malloc(sizeof(char) * strlen(src));
	char *delim = " ";
	char *token;

	strcpy(dest, src);
	token = strtok(dest, delim);

	while(token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	free(dest);
	return(0);;
}
