/**
* vigenere.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Encrypts some plaintext with the vigenere cipher.
*/

 #include <stdio.h>
 #include <cs50.h>
 #include <math.h>
 #include <ctype.h>
 #include <string.h>

 int main(int argc, string argv[])
 {
 	short uic = 1;

 	// check keyword K user input for correctness.
 	if(argc == 2)
 	{
 		uic = 0;
 		for (short i = 0, argl = strlen(argv[1]); i < argl; ++i)
 		{
 			if(!isalpha(argv[1][i]))
 				++uic;
 		}
 	}
 	if(uic)
 	{
 		printf("A keyword (string) of alphabets only will suffice !\n");
 		return 1;
 	}

 	// obtain text P from user.
 	string K = argv[1];
 	string T = GetString();

 	// setup keyword counter for auto reset.
 	short RKC = 0;
 	short KL = strlen(K);
 	short TL = strlen(T);
 	if(TL > KL)
 		RKC = 1;

	// encrypt T with K.
	char t, k, c;
	short TAR, KAR, tpa, kpa, cpa;
	for (short i = 0, j = 0; i < TL; ++i)
	{
		t = c = T[i];
		k = K[j];
		if(isalpha(t))
		{
			TAR = (isupper(t)) ? 64 : 96;
			KAR = (isupper(k)) ? 65 : 97;

			tpa = t - TAR;
			kpa = k - KAR;

			cpa = tpa + kpa;
			cpa = cpa == 26 ? cpa : cpa % 26;
			c = cpa + TAR;

			if(RKC && (j == KL - 1))
				j = -1;
			++j;
		}
		T[i] = c;
	}

	// display T.
	printf("%s\n", T);
 }