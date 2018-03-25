/**
* structpointer.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Struct pointers manipulations.
**/

#include <stdio.h>
#include <stdlib.h>

typedef struct persons
{
    int ssid;
    char* name;
} person;

int main (void)
{
    person* p = malloc(sizeof(person));
    p -> ssid = 357;
    p -> name = "Cheick Ali M. DIALLO";

    printf("SSID: %d \t Name: %s \n", p -> ssid, p -> name);
}