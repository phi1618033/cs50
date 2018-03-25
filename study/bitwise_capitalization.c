/**
 * BitwizeCapitalization.c
 *
 * Cheick Ali M. DIALLO
 * cheickalimdiallo@gmail.com
 *
 * Capitalizes a lowercase letter.
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 int main(int argc, string argv[])
 {
    int lcl;
     
    printf("Please enter a lowercase letter: ");
    lcl = GetChar();
    while(lcl < 97 || lcl > 122)
    {
        printf("Retry: ");
        lcl = GetChar();
    }
    
    int uce = lcl ^ 32;
    
    printf("%c\n", uce);
 }