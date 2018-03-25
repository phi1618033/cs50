/**
* contains.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Returns true if a node in the linked list contains int i and false otherwise.
**/

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct node
{
    // the value to store in this node
    int n;

    // the link to the next node in the list
    struct node* next;
}
node;

node* head = NULL;

bool contains(int i)
{
    // point to the head node
    node* ptr = head;

    // go down the linked list and check the value of each node
    while(ptr != NULL)
    {
        if(ptr->n == i)
            return true;
        ptr = ptr->next;
    }
    return false;
}

int main(int argc, char* argv[])
{
    // create linked list
    for (int i = SIZE; i > 0; i--)
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

    printf("What value are you looking for? ");
    int i = GetInt();

    if (contains(i))
    {
        printf("Found it! The list contains ");
    }
    else
    {
        printf("Sorry, the list only contains ");
    }
    for (node*  ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->n);
    }
    printf("\n");

    return 0;
}
