/**
 * greedy-1.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Displays the minimum number of coins.
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
    float amount;
    int left, cents, count;

    count = 0;

    // prompts the user for the amount of the change.
    printf("O hai! How much change is owed?\n");
    scanf("%f", &amount);
    while(amount < 0)
    {
        printf("Retry: ");
        scanf("%f\n", &amount);
    }

    cents = (int)round(amount * 100);
    left = cents;

    // computes the number of coins
    count += left / 25; // the number of 25 cent coin.
    left %= 25; // the remaining amount.

    count += left / 10;
    left %= 10; 

    count += left / 5; 
    left %= 5; 

    count += left / 1; 
    left %= 1;

    // displays the number of coins.
    printf("%i\n", count);
}