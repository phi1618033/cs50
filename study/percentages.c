/**
 * percentages.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Prints a fraction as a percent to 2 decimal places.
 */

 #include <stdio.h>
 #include <cs50.h>

 int main(int argc, string argv[])
 {
 	float num;
 	do
 	{
 		printf("non-negative numerator: ");
 		num = GetFloat();
 	}
 	while(num < 0);

 	float den;
 	do
 	{
 		printf("positive denominator: ");
 		den = GetFloat();
 	}
 	while(den < 1);
 	
 	float percent = (num / den) * 100.00;

 	printf("%.2f%%\n", percent);
 }