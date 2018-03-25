/**
 * greedy.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Displays the minimum number of coins.
 */

#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float change;
    int left, coin, number_of_coins;

    number_of_coins = 0;
    coin = 25;

    // Prompts the user for the amount of the change.
    printf("O hai! How much change is owed?\n");
    change = GetFloat();
    while(change < 0)
    {
        printf("Retry: ");
        change = GetFloat();
    }

    change = change * 100;
    left = round(change);

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
        ++number_of_coins;
    }

    // Displays the number of coins.
    printf("%i\n", number_of_coins);
}