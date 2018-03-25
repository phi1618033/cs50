/***************************************************************************
* stringmanip.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* String reading and manipulation in C.
***************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)

char* text;

char* trim(char* txt)
{
	// remove leading spaces
	while(isspace(*txt))
		txt++;
	if(*txt == 0)
		return txt;
	// remove trailing spaces
	int length = strlen(txt);
	char* bw_txt = txt + length - 1;
	// UNUSED(bw_txt);
	while(bw_txt > txt && isspace(*bw_txt)) 
		bw_txt--;
	
	// write new null terminator
	*(bw_txt + 1) = 0;
	return txt;
}

char* second_word(char* txt)
{
	while(!isspace(*txt))
		txt++;
	return ++txt;
}

char* to_upper(char* txt)
{
	char* b_txt = txt;
	while(*b_txt != 0)
	{
		*b_txt = toupper(*b_txt);
		b_txt++;
	}
	return txt;
}

int main(void)
{
	// get string from user
	printf("Full name: ");
	text = GetString();
	printf("As is: %s\n", text);
	text = trim(text);
	printf("Trimmed: %s\n", text);
	text = second_word(text);
	printf("Last name: %s\n", text);
	text = to_upper(text);
	printf("All CAPS: %s\n", text);
}