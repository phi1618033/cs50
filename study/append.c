/**
* append.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Appends a new node containing int i at the end of a singly linked list.
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void append(int i)
{
    // create a new node with i as value
    node* new = malloc(sizeof(node));
    new->n = i;
    new->next = NULL;

    // point to the head node
    node* ptr = head;

    if(ptr != NULL)
    {
        // retrieve the last node
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        // make the last node point to the new node
        ptr->next = new;
    }
    else
    {
        // in case the linked list is empty, insert the new node as head
        head = new;
    }
}

int main(int argc, char* argv[])
{
    // creating list
    printf("Appending ints 0-%i onto the list...\n", SIZE - 1);
    for (int i = 0; i < SIZE; i++)
    {
        append(i);
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
