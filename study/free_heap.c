/**
* free_heap.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Free all heap memory used.
**/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* ptr = malloc(sizeof(char) * 7);
    char* _ptr = ptr;

    for (int i = 0; i < 6; i++)
        *(ptr + i) = 'z';

    ptr[6] = '\0';

    while (*ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");

    // TODO: free heap memory!
    free(_ptr);
}