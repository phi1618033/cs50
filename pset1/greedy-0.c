/**
 * greedy-0.c
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
    int left, coin, count;

    count = 0;
    coin = 25;

    // Prompts the user for the amount of the amount.
    printf("O hai! How much amount is owed?\n");
    scanf("%f", &amount);
    while(amount < 0)
    {
        printf("Retry: ");
        scanf("%f", &amount);
    }

    amount = amount * 100;
    left = round(amount);

    // Computes the number of coins
    while(left > 0)
    {
        if(left > 25)
            coin = 25;

        if(left < 25  && left >= 10)
            coin = 10;

        if(left < 10  && left >= 5)
            coin = 5;

        if(left < 5)
            coin = 1;

        left -= coin;
        ++count;
    }

    // Displays the number of coins.
    printf("%i\n", count);
}