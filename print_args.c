#include <stdio.h>

int main(int argc, char *argv[])
{
	int avc = 0, i = 0;
	//argv is a null terminated string
	while(*argv)
	{
		argv++;
		avc++;
	}

	printf("My av arguemnets are: %d\n", avc);
	printf("The argc is: %d\n", argc);

	while(*argv)
	{
		printf("%s\n",(*argv));
		argv++;
	}
	return(0);
}
