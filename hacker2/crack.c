/***************************************************************************
* crack.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Cracks a password encrypted with C's DES-based crypt function. The length
* of the password is less than or equal to 8 characters.
***************************************************************************/

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)

// symbolic constants
#define MAX_PASSPHRASE_LENGTH 8
#define ENCRYPTED_PWD_LENGTH 13
#define SALT_LENGTH 2

// global variables
char encrypted_password[ENCRYPTED_PWD_LENGTH];
char salt[SALT_LENGTH];
bool matched;

// prototypes
bool match(char* key);
void brute_force(char phrase[], size_t index, size_t length, char first, char last);

int main(int argc, char* argv[])
{
    // check number of arguments
    if(argc != 2)
    {
        printf("Usage: ./crack encrypted_password\n");
        return 1;
    }

    // get encrypted password and salt
    size_t argv1_size= strlen(argv[1]) * sizeof(char);
    strncpy(encrypted_password, argv[1], argv1_size);
    salt[0] = encrypted_password[0]; 
    salt[1] = encrypted_password[1];

    char passphrase[MAX_PASSPHRASE_LENGTH + 1];
    //  fill the array with NULLs
    memset(passphrase, 0, MAX_PASSPHRASE_LENGTH + 1);
    // check all combinations of printable ascii characters
    matched = false;
    brute_force(passphrase, 0, MAX_PASSPHRASE_LENGTH, 32, 57);

    return 0;
}

/*
* Checks whether the encrypted key with the corresponding salt matches 
* the encrypted_password.
*/
bool match(char* key)
{
    if(strcmp(crypt(key, salt), encrypted_password) == 0)
        return true;
    return false;
}

/*
* Brute force attack: Encrypt each combination of ASCII printable character
* and match it with the encrypted_password supplied.
*/
void brute_force(char* phrase, size_t index, size_t length, char first, char last)
{
    if(matched == true)
        return;

    char c;

    if (index < (length - 1)) 
    {
        for (c = first; c <= last; ++c) 
        {
            phrase[index] = c;
            brute_force(phrase, index + 1, length, first, last);
        }
    } 
    else 
    {
        for (c = first; c <= last; ++c) 
        {
            phrase[index] = c;
            char* __phrase = phrase;
            while(isspace((unsigned char)*__phrase))
                ++__phrase;
            printf("%s\n", __phrase);
            if(match(__phrase))
            {
                // printf("%s\n", __phrase);
                matched = true;
                break;
            }
        }
    }
}