/**
* prepend.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Prepends a new node containing <tt>int i</tt> to the front of a singly linked list.
**/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node
{
    // the value to store in this node
    int n;

    // the link to the next node in the list
    struct node* next;
}
node;

node* head = NULL;

void prepend(int i)
{
    // create a new node with i as value
    node* new = malloc(sizeof(node));
    new->n = i;

    // make the new node the head
    new->next = head;
    head = new;
}

int main(int argc, char* argv[])
{
    // creating list
    printf("Prepending ints 0-%i onto the list... ", SIZE - 1);
    for (int i = 0; i < SIZE; i++)
    {
        prepend(i);
    }
    printf("done!\n");

    // printing out list
    printf("Your list contains ");
    for (node*  ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->n);
    }
    printf("\n");

    return 0;
}
