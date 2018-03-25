/**
 * grades.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Shows corresponding level from grade.
 */

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    do
    {
        printf("Enter a valid grade: ");
        n = GetInt();
    }
    while (n > 100 || n < 60);

    // if n is between 90 and 100
    if (n >= 90)
        printf("You got an A!\n");

    // if n is between 80 and 90
    if (n < 90 && n >= 80)
        printf("You got a B!\n");

    // if n is between 70 and 80
    if (n < 80 && n >= 70)
        printf("You got a C!\n");

    // if n is between 60 and 70
    if (n < 70 && n >= 60)
        printf("You got a D!\n");
}