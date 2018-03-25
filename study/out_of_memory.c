/**
* out_of_memory.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* A program that continuously mallocs a single byte until malloc(1) fails. 
* Prints out how many times malloc(1) was successful.
**/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* string;
    int noa = 0;

    do
    {
        string = malloc(1);
        if(string == NULL)
            break;
        ++noa;
    }
    while(1);

    printf("%d\n", noa);
}