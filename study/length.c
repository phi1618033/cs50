/**
* length.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Returns the length of a singly linked list.
**/

#include <assert.h>
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


/* Returns the length of a singly linked list. */
int length(void)
{
    // initialize the counter to 0
    int count = 0;

    // point to head
    node* ptr = head;

    // go through the linked list and count the number of node
    while(ptr != NULL)
    {
        ++count;
        ptr = ptr->next;
    }
    return count;
}

int main(int argc, char* argv[])
{
    // create linked list
    for (int i = 0; i < SIZE; i++)
    {
        node* new = malloc(sizeof(node));

        if (new == NULL)
        {
            exit(1);
        }
        new->n = i;
        new->next = head;
        head = new;
    }

    printf("Making sure that list length is indeed %i...\n", SIZE);

    // test length function
    assert(length() == SIZE);
    printf("good!\n");

    return 0;
}
