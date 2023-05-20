#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *path = getenv("PATH");
	char *delim = ":";
	char *token = strtok(path, delim);

	while(token)
	{
		char filename[256];

		//creating the full path to the file
		snprintf(filename, sizeof(filename), "%s%s", token, argv[1]);

		FILE *file;
		file = fopen(filename, "r");

		if(file != NULL)
		{
			printf("File '%s' found at: %s\n", argv[1], filename);
			fclose(file);
			return 0;
		}

		token = strtok(NULL, delim);
	}
	printf("File '%s' not found in the PATH.\n", argv[1]);
	return 1;
}
