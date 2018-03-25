/**
 * water.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Displays the number of bottles from the length of the shower.
 */

#include <stdio.h>
#include <cs50.h>

#define BOTTLES_PER_MINUTE 12

int main(void)
{
    int minutes, bottles;
    
    // Prompts the length (in minutes) of the shower
    printf("minutes: ");
    minutes = GetInt();
    
    // Checks for a positive number of minutes
    while(minutes < 1)
    {
        printf("minutes: ");
        minutes = GetInt();
    }
    
    // Compute the number of bottles
    bottles = minutes*BOTTLES_PER_MINUTE;
    
    // Prints the equivalent number of bottles of water
    printf("bottles: %i \n", bottles);
}