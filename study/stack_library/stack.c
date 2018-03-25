/***************************************************************************
* stack.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Stack Library - This library offers the minimal stack operations for a stack of integers.
***************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

typedef struct stack_type
{
    stack_data data;
    struct stack_type* next;
}
stack;

stack* top = NULL;

void stack_init()
/* Initializes this library.
   Call before calling anything else. */
{
    top = NULL;
}

void stack_clear()
/* Clears the stack of all entries. */
{
    stack_data d;

    while (!stack_empty())
        d = stack_pop();
}

bool stack_empty()
/* Returns 1 if the stack is empty, 0 otherwise. */
{
    if (top == NULL)
        return true;
    else
        return false;
}

void stack_push(stack_data d)
/* Pushes the value d onto the stack. */
{
    stack* new = malloc(sizeof(stack));
    new->data = d;
    new->next = top;
    top = new;
}

stack_data stack_pop()
/* Returns the top element of the stack,
   and removes that element.
   Returns garbage if the stack is empty. */
{
    stack_data d = 0;
    if(!stack_empty())
    {
        d = top->data;
        top = top->next;
    }
    return d;
}

/* Duplicates the top element of the stack. */
void stack_dup()
{
    stack_push(top->data);
}

/* Returns a count of the number of elements in the stack. */
int stack_count()
{
    int count = 0;
    stack* ll = top;
    while(ll != NULL)
    {
        ++count;
        ll = ll->next;
    }
    return count;
}