/**
 * mario.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Outputs Mario's half-pyramid.
 */
 
#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int height, line, number_of_hashes, number_of_spaces;
    
    // prompts the user for the height.
    printf("height: ");
    height = GetInt();
    while(height < 0 || height > 23)
    {
        printf("Retry: ");
        height = GetInt();
    }
    
    // draws the half-pyramid.
    for(line = 1; line <= height; line++)
    {
        // the number of spaces before hashes for the current line.
        number_of_spaces = height - line;
        while(number_of_spaces > 0)
        {
            printf(" ");
            number_of_spaces--;
        }
        
        // prints the half-pyramid.
        number_of_hashes = line + 1;
        while(number_of_hashes > 0)
        {
            printf("#");
            number_of_hashes--;
        }
        printf("\n");
    }
}