#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * number_of_tokens -  the function calculates the number of words
 * passed to standard input
 * @str: the string we are counting the words in
 *
 * Return: returns the number of word in a string
 */

int number_of_tokens(char *str)
{
	char *token = NULL;
	char *delim = " \n";
	int argc = 0;

	token = strtok(str, delim);
	while(token)
	{
		token = strtok(NULL, delim);
		argc++;
	}
	return (argc);
}


int main(void)
{
	char *cmd = NULL;
	char *cmd_cpy = NULL;
	char *token = NULL;
	char *delim = " \n"; //the delimeter is a whitespace followed by a new line
	size_t buffer_size = 0;
	int argc = 0, i = 0, index = 0;
	char **argv = NULL;

	printf("$");
	if (getline(&cmd, &buffer_size, stdin) == -1)
		return(-1);

	cmd_cpy = strdup(cmd);

	argc = number_of_tokens(cmd);

	printf("%d\n", argc);

	argv = malloc(sizeof(char *) * argc);

	//define the individual elements of the array
	token = strtok(cmd_cpy, delim);
	while(token)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;

	//printing out the elements of argv
	while(argv[index])
	{
		printf("%s\n", argv[index]);
		index++;
	}

	//freeing the memory
	free(cmd);
	free(cmd_cpy);
	free(argv);

	return(0);
}
