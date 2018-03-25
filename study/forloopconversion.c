/**
 * forloopconversion.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * ...
 */

#include <stdio.h>
#include <cs50.h>

int main(int argc, char const *argv[])
{
	// for (int i = 0; i < 5; i++)
 	//    	for (int j = 0; j < 5; j++)
 	//        	printf("i = %d, j = %d\n", i, j);

	// iterate from 0 through 25
	for (int i = 0, j = 0, k = 0; k < 25; ++k)
	{
		// use division and mod to print combos of numbers
		printf("i = %d, j = %d\n", i, j);
		if(j == 4)
		{
			j = -1;
			++i;
		}
		++j;
	}
	return 0;
}