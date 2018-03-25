/**
* caesar.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Uses a ROT-k algorithm to encrypt plain-text using the caesar cipher algorithm.
*/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main (int argc, string argv[])
{
	int k;
	bool uic = false;

	// check the supplied key value.
	if(argc == 2)
	{
		k = atoi(argv[1]);
		if(k >= 0 && k < pow(2,31)-26)
			uic = true;
	}

	// exit if the key is not validated.
	if(!uic)
	{
		printf("Supply an integer in [0, 2^(31) - 26[ as one argument !\n");
		return 1;
	}

	// obtain plaintext from user.
	printf("plaintext: ");
	string text = GetString();

	// encrypt plaintext with Caesar cipher.
	short pa, AR;
	pa = AR = 0;
	char c = '\0';
	for (int i = 0, text_length = strlen(text); i < text_length; ++i)
	{
		c = text[i];
		if(isalpha(c))
		{
			// get char's corresponding ascii decimal value
			AR = (isupper(c)) ? 64 : 96;
			pa = c - AR;
			// shift char to k positions
			c = ((pa + k) % 26) + AR;
		}
		text[i] = c;
	}

	// display cipher text.
	printf("ciphertext: %s\n", text);
}