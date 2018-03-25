/**
* initials.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Outputs initials of names in uppercase with no spaces or periods.
*/

 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 #include <ctype.h>

 int main()
 {
 	string names;
 	char initials[10];

 	// obtain user names.
 	names = GetString();

 	// get the first letter of each word in name.
 	short i = 0;
 	initials[i] = toupper(names[i]);
 	for (short len = strlen(names), n = 1; n < len; ++n)
 	{
 		if(names[n] == ' ')
 			initials[++i] = toupper(names[++n]);
 	}
 	initials[++i] = '\0';

 	printf("%s\n", initials);
 	return 0;
 }