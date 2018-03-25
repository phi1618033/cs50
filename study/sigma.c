/**
* sigma.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Adds the numbers 1 through n and returns the sum.
**/

#include <stdio.h>
#include <cs50.h>

int sigma(int n)
{
    if(n < 2)
        return 1;
    else
        return n + sigma(n-1);
}

int main(int argc, char* argv[])
{
    // ask user for a positive integer
    int n;
    do
    {
        printf("Enter a positive integer: ");
        n = GetInt();
    }
    while (n < 1);
    
    // report answer
    printf("%i\n", sigma(n));
}