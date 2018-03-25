/**
* insertsorted.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Inserts a new node containing int i into the appropriate position in a list sorted in ascending order.
**/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 15

typedef struct node
{
    // the value to store in this node
    int n;

    // the link to the next node in the list
    struct node* next;
}
node;

node* head = NULL;

void prepend(node* prev, node* curr, node* topr)
{
    if(prev == NULL)
    {
        topr->next = curr;
        head = topr;
    }
    else
    {
        topr->next = curr;
        prev->next = topr;
    }
}

void append(node* curr, node* toap)
{
    node* nxt = curr->next;
    if(nxt == NULL)
    {
        curr->next = toap;
    }
    else
    {
        toap->next = nxt;
        curr->next = toap;
    }
}

void insert_sorted(int i)
{
    // create a new node with i as value
    node* new = malloc(sizeof(node));
    new->n = i;
    new->next = NULL;

    // if the linked list is empty
    if(head == NULL)
    {
        // set the new node as the first node
        head = new;
    }
    else
    {
        node* ptr = head;
        node* nxt = ptr->next;
        if(head->n > i)
        {
            new->next = head;
            head = new;
        }
        else
        {
            while((nxt = ptr->next) != NULL)
            {
                if(i > ptr->n && i < nxt->n)
                {
                    new->next = nxt;
                    ptr->next = new;
                    break;
                }
                ptr = ptr->next;
            }
            if(i > ptr->n)
            {
                ptr->next = new;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    printf("Inserting %i random ints to the list...\n", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        int rn = rand() % SIZE;
        insert_sorted(rn);
        printf("%d ", rn);
    }
    printf("done!\n");

    // printing out list
    printf("Your list now contains ");
    for (node*  ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%i ", ptr->n);
    }
    printf("\n");

    return 0;
}
