/**
* echo.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Implementation of a UNIX-like echo program.
**/

#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
	if(argc < 2)
	{
		printf(" \n");
		return 0;
	}

	for(int i = 1; i < argc; i++)
	{
		printf("%s ", argv[i]);
	}


	printf("\n");
}
