/***************************************************************************
* stack_pop.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Implement a pop function for a stack.
***************************************************************************/

// for strdup() in the testing code
#define _XOPEN_SOURCE 500

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the capacity of the stack
#define CAPACITY 10

typedef struct
{
    // storage for the elements in the stack
    char* strings[CAPACITY];

    // the number of elements currently in the stack
    int size;
}
stack;

// declare a stack (as a global variable)
stack s;

/**
 * Retrieves ("pops") the last ("top") element off of the stack, following
 * the "last-in, first-out" (LIFO) ordering of the data structure. Reduces
 * the size of the stack.
 */
char* pop(void)
{
    // check that stack is not empty
    if(s.size == 0)
        return NULL;
    // decrement stack length
    --s.size;
    // reurn string
    return s.strings[s.size];
}

/**
 * Implements some simple test code for our stack
 */
int main(void)
{
    // initialize the stack
    s.size = 10;

    printf("Pushing %i strings onto the stack...", CAPACITY);
    for (int i = 0; i < CAPACITY; i++)
    {    
        char str[12];
        sprintf(str, "%i", i);
        s.strings[i] = strdup(str);
    }
 
    printf("done!\n");

    printf("Popping everything off of the stack...");
    char* str_array[CAPACITY];
    for (int i = 0; i < CAPACITY; i++)
    {
        str_array[i] = pop();
    }
    printf("done!\n");

    printf("Making sure that pop() returned values in LIFO order...");
    for (int i = 0; i < CAPACITY; i++)
    {
        char str[12];
        sprintf(str, "%i", CAPACITY - i - 1);
        assert(strcmp(str_array[i], str) == 0);
        free(str_array[i]);
    }
    printf("good!\n");

    printf("Making sure that the stack is now empty...");
    assert(s.size == 0);
    printf("good!\n");

    printf("Making sure that pop() now returns NULL...");
    assert(pop() == NULL);
    printf("good!\n");

    printf("\n********\nSuccess!\n********\n");

    return 0;
}