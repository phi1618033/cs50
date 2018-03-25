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
    
    // prompts the length (in minutes) of the shower
    printf("minutes: ");
    minutes = GetInt();
    
    // compute the number of bottles
    bottles = minutes * BOTTLES_PER_MINUTE;
    
    // prints the equivalent number of bottles of water
    printf("bottles: %i \n", bottles);
}