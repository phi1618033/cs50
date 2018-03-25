/**
* strchr.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Implement strchr(), a standard function that returns a substring of a C string that starts with a given character. 
* If the character is not in the string, it should return NULL.
**/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

char* my_strchr(char* str, char c)
{
    for(int i = 0, count = strlen(str); i < count; ++i)
    {
        if(str[i] == c)
        {
            char* ss = malloc((count - i + 1) * sizeof(char));
            if(ss == NULL)
                return NULL;
            for(int j = 0; i <= count; ++i, ++j)
            {
                *(ss + j) = *(str + i);
            }
            return ss;
        }
    }

    return NULL;
}

int main(void)
{
    printf("String: ");
    char* str = GetString();
    printf("Character: ");
    char c = GetChar();
    printf("Looking for substring...\n");
    char* result = my_strchr(str, c); 
    if (result == NULL)
    {
        printf("Couldn't find %c.\n", c);
    }
    else
    {
        printf("Substring: %s \n", result);
    }
}