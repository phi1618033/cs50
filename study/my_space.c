/**
 * Myspace.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Capitalizes the first letter and alternates the case of all letters.
 * 
 * Assumptions: The user will only input lowercase letters and spaces.
 */
 
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main (int argc, string argv[])
{
    string text;
    unsigned int i, u;
    
    text = GetString();
    
    unsigned int text_length = strlen(text);

    i = u = 0;
    while(i <  text_length)
    {
    	if((unsigned int)text[i] != 32 && u == 0)
    	{
    		text[i] = toupper(text[i]);
    		u = 1;
    	}
    	else if((unsigned int)text[i] != 32)
    	{
    		u = 0;
    	}
    	i += 1;
    }

    printf("%s\n", text);
}