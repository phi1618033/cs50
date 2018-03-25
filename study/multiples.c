/**
 * multiples.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Prints the multiples of a number between 1 and 100.
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
	unsigned short n;

	do
	{
		printf("Give me a number between 1 and 100: ");
		n = GetInt();
	}
	while(n < 1 || n > 100);

	unsigned short i = 1;
	unsigned short m = n * i;

	do
	{
		printf("%d ", m);
		++i;
		m = n * i;
	}
	while(m <= 100);
	printf("\n");
}