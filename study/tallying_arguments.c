/**
 * TallyingArguments.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Prints out the total number of characters in the command line arguments given to the program.
 */

 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>

 int main(int argc, string argv[])
 {
 	unsigned short count = 0;

 	if(argc < 2)
 	{
 		printf("%d characters were given.\n", count);
 		return 0;
 	}

 	for(unsigned short i = 1; i < argc; ++i)
 	{
 		unsigned short cnt = strlen(argv[i]);
 		for (int j = 0; j < cnt; ++j)
 		{
 			if(argv[i][j] != ' ')
 				++count;
 		}
 	}

 	printf("%d characters were given.\n", count);
 }