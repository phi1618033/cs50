/***************************************************************************
* hash_function.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* A hash function for strings that sums the ASCII values of the argument key's characters.
***************************************************************************/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int hash_function(char* key, int size)
{
    int sum = 0;
    for(int i = 0, length = strlen(key); i < length; ++i)
    {
        sum += toupper(key[i]);
    }
    return sum % size;
}

int main(void)
{
    // get hash table size
    printf("Hash table size: ");
    int size = GetInt();

    // get key
    printf("Key: ");
    char* key = GetString();

    // calculate and print index
    printf("The string '%s' is mapped to index %i\n", key, 
    hash_function(key, size));

    return 0;
}
