/***************************************************************************
* libfifteen.h
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* A library of data structures and functions for the N-puzzle game god mode.
***************************************************************************/

#include <stdbool.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// defined types
// a linked list data structure for the A* algorithm implementation
typedef struct node_type
{
    int board[DIM_MAX][DIM_MAX];
    int g;
    int h;
    int f;
    struct node_type* parent;
    struct node_type* child;
} node;

/*
* Copies the source board content into the destination board content.
*/
void board_copy(int dest[DIM_MAX][DIM_MAX], int src[DIM_MAX][DIM_MAX], int dim);

/*
* Insert a node at the end of a list of nodes.
*/
void node_add(node* list, node* element);

/*
* Compare two boards.
*/
bool board_compare(int a[DIM_MAX][DIM_MAX], int b[DIM_MAX][DIM_MAX], int dim);

/*
* Remove a node from a list.
*/
void node_remove(node* list, node* element, int dim);

/*
* Returns the number of nodes in the list.
*/
int node_count(node* list);