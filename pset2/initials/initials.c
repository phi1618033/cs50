/**
* initials.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Outputs their initials in uppercase with no spaces or periods.
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
	string user_name;

	// Prompts the user for his name.
	user_name = GetString();

	// Gets initials from the name.
	int count, i, j;

	count = strlen(user_name);
	char name[count];
	strcpy(name, user_name);

	char initials[count];
	initials[0] = name[0];
	j = 1;

	for(i = 1; i < count; i++)
	{
		if(name[i] == ' ' && i+1 < count)
		{
			initials[j] = !isupper(initials[j]) ? toupper(name[i+1]) : name[i+1];
			++j;
		}
	}
	initials[count - 1] = '\0';

	// Prints the initials.
	printf("%s\n", initials);
}