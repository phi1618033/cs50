/**
 * pokemon.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Prompts the user to input the names of five Pokemon. 
 * Store those Pokemon in an array, 
 * and randomly select one to print out.
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

int main(int argc, string argv[])
{
    // declare array storage for Pokemon
    string pokeball[MAX] = {""};

    // collect and store Pokemon
    for (int i = 0; i < 5; ++i)
    {
    	printf("Give me a pokemon: ");
    	pokeball[i] = GetString();
    }

    // choose and print out random Pokemon
    	// rand() % (max_number + 1 - minimum_number) + minimum_number
    srand(time(NULL));
    int rn = rand() % (4 + 1 - 0) + 0;
    printf("%s, I choose you!\n", pokeball[rn]);
}