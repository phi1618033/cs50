/**
 * mario.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Outputs Mario's 2 halfs pyramids according to height.
 */

 #include <stdio.h>
 #include <cs50.h>

 int main()
 {
 	short height, spaces, hashes;

 	// obtain the height from user.
 	do
 	{
 		printf("Height: ");
 		height = GetInt();
 	}
 	while(height < 0 || height > 23);

 	for (int v = 1; v <= height; ++v)
 	{
 		// display spaces before #.
 		spaces = height - v;
 		for (int a = 0; a < spaces; ++a)
 			printf(" ");

 		// display #.
 		hashes = v;
 		for (int a = 0; a < 2; ++a)
 		{
 			for (int l = 1; l <= hashes; ++l)
 			{
 				printf("#");
 			}
 			if(a == 0)
 				printf("  ");
 		}
 		printf("\n");
 	}

 	return 0;
 }