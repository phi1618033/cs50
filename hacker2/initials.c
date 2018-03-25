/***************************************************************************
* initials.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* A program that prompts users for their name outputs their initials in
* uppercase with no spaces or periods.
***************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // get user's name
    string name = GetString();
    size_t name_length = strlen(name);

    // the number of initials cannot be more than the number of characters
    char initials[name_length];
    // initials array index
    size_t j = 0;
    if(isalpha(name[0]))
        initials[j++] = toupper(name[0]);
    for(size_t i = 1; i < name_length; i++)
    {
        // if a char is preceded by a space and is an alphabetic char
        if(name[i-1] == ' ' && isalpha(name[i]))
 			initials[j++] = toupper(name[i]);
    }
    initials[j] = '\0';

    printf("%s\n", initials);
 	return 0;

}