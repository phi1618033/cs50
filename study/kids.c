/**
 * kids.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Guess at the average number of children per family in the United States.
 */

 #include <cs50.h>
 #include <stdio.h>

 int main(void)
 {
 	printf("Average number of children per family in US: ");
 	unsigned short n = GetInt();
 	if(n == 2)
 		printf("That is correct!\n");
 	else
 		printf("That is incorrect!\n");
 }