/**
 * square.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Prints a n by n square of hashes.
 */

 #include <stdio.h>
 #include <cs50.h>

 int main(void)
 {
 	unsigned int n;

 	printf("Give me a number between 1 and 23: ");
 	n = GetInt();
 	while(n < 1 || n > 23)
 	{
 		printf("Retry: ");
 		n = GetInt();
 	}

 	for(int i = 0; i < n; ++i)
 	{
 		for (int j = 0; j < n; ++j)
 		{
 			printf("#");
 		}
 		printf("\n");
 	}
 }