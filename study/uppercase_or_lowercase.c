/**
 * lettercase.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Displays the case of a letter.
 */
 
 

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // Collect user input
    printf("Please enter an alphabetical character: ");
    char c = GetChar();

    // If letter is uppercase
    if (c >= 'A' && c <= 'Z')
        printf("Thank you for the uppercase letter!\n");

    // If the letter is lowercase
    else if (c >= 'a' && c <= 'z')
        printf("Thank you for the lowercase letter!\n");

    // If not an alphabetical character
    else
        printf("You did not enter an alphabetical character!\n");
}