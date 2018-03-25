/***************************************************************************
* driver.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Implementation of the Stack Library.
***************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

int main(void)
{
    stack_init();

    stack_push(3);
    printf("%d added to stack\n", 3);

    stack_push(5);
    printf("%d added to stack\n", 5);

    stack_push(7);
    printf("%d added to stack\n", 7);
    
    stack_dup();
    printf("top stack duplicated\n");
    
    printf("%d elements in stack\n", stack_count());

    printf("%d and %d popped from stack\n", stack_pop(), stack_pop());

    stack_clear();
    printf("stack cleared\n");

    printf("stack is %s\n", (stack_empty()) ? "empty" : "not empty");
}