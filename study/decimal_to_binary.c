/**
 * DecimalToBinary.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Prints the binary representation of a number.
 */

 #include <stdio.h>
 #include <cs50.h>

 int main(void)
 {
 	// Prompts the user for a positive decimal.
 	printf("Please enter a positive decimal value: ");
 	int dec = GetInt();
 	while(dec < 0)
 	{
 		printf("Retry: ");
 		dec = GetInt();
 	}

 	// Generates binaries from the decimal.
 	char bin[32];
 	unsigned short i = 0;
 	unsigned int dvd, quo;
 	dvd = dec;
 	do
 	{
 		quo = dvd / 2;
 		bin[i] = dvd % 2;
 		//printf("%i -> %i div 2 = %i\n", i, dvd, bin[i]);
 		dvd = quo;
 		++i;
 	}
 	while(quo > 0);

 	// Displays everything.
 	short j = i - 1;
 	for(; j >= 0; j--)
 	{
 		printf("%i", bin[j]);
 	}
 	printf("\n");
 }