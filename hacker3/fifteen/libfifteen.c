/***************************************************************************
* libfifteen.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* A library of data structures and functions for the N-puzzle game god mode.
***************************************************************************/

#include <stdbool.h>
#include <stdlib.h>

#include "libfifteen.h"

/*
* Copies the source board content into the destination board content.
*/
void board_copy(int dest[DIM_MAX][DIM_MAX], int src[DIM_MAX][DIM_MAX], int dim)
{
    // traverse both boards at the same time
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            // assign values
            dest[i][j] = src[i][j];
        }
    }
}

/*
* Insert a node at the end of a list of nodes.
*/
void node_add(node* list, node* element)
{
    element->child = NULL;
    if(list == NULL)
    {   
        element->parent = NULL;
        list = element;
        return;
    }

    // point to the first element in the list
    node* current = list;
    // traverse the list and stop at the last node
    while(current->child != NULL)
    {
        current = current->child;
    }
    // insert the node/element
    current->child = element;
}

/*
* Compare two boards.
*/
bool board_compare(int a[DIM_MAX][DIM_MAX], int b[DIM_MAX][DIM_MAX], int dim)
{
    bool alike = true;

    // traverse both boards and
    for(int i = 0; i < dim; ++i)
    {
        for(int j = 0; j < dim; ++j)
        {
            // check for differences
            if(a[i][j] != b[i][j])
            {
                alike = false;
                return alike;
            }
        }
    }

    return alike;
}

/*
* Remove a node from a list.
*/
void node_remove(node* list, node* element, int dim)
{
    if(list == NULL)
        return;

    node* current = list;
    while(current != NULL)
    {
        if(board_compare(current->board, element->board, dim))
        {
            if(current->child == NULL)
            {
                // node* _current = current;
                current = current->parent;
                // free(_current);
                current->child = NULL;
            }
            else
            {
                node* parent = current->parent;
                parent->child = current->child;
                // free(current);
            }
        }
        current = current->child;
    }
}

/*
* Returns the number of nodes in the list.
*/
int node_count(node* list)
{
    // point to the first node in the list
    node* current = list;
    int counter = 0;
    while(current != NULL)
    {
        // count
        counter += 1;
        current = current->child;
    }
    return counter;
}
