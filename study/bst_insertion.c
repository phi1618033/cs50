/***************************************************************************
* bt_insertion.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Inserts values into a binary search tree.
***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int n;
    struct node* left;
    struct node* right;
}
node;

node* root;

bool insert(int val)
{
    // create a new node with value val
    node* new = malloc(sizeof(node));
    new->n = val;
    new->left = NULL;
    new->right = NULL;

    // a node for traversing the tree always from the root
    node* tree = root;
    // while there exist a node
    while(tree != NULL)
    {
        // a node with value val already exists
        if(val == tree->n)
            return false;
        
        /* pick node to traverse next, left or right,
           if node does not exists insert new node */
        if(val < tree->n)
        {
            if(tree->left == NULL)
            {
                tree->left = new;
                return true;
            }
            else
                tree = tree->left;
        }
        else
        {
            if(tree->right == NULL)
            {
                tree->right = new;
                return true;
            }
            else
                tree = tree->right;
        } 
    }
    return false;
}

bool search(node* root, int val)
{
    // if root is NULL
    if (root == NULL)
    {
        // return false
        return false;
    }		
    // if root->n is val	
    if (root->n == val)
    {
        // return true
        return true;
    }	
    // if val is less than root->n	
    else if (val < root->n)
    {
        // search left child
        return search(root->left, val);
	}	
    // if val is greater than root->n	
    else
    {
        // search right child
        return search(root->right, val);
    }
}

int main(void)
{
    // create root node
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        printf("Out of memory!\n");
        return 1;
    }
    root->n = 7;
    root->left = NULL;
    root->right = NULL;
    
    // create more nodes
    node* three = malloc(sizeof(node));
    if (three == NULL)
    {
        printf("Out of memory!\n");
        return 1;
    }
    three->n = 3; 
    three->left = NULL;
    three->right = NULL;
    
    node* six = malloc(sizeof(node));
    if (six == NULL)
    {
        printf("Out of memory!\n");
        return 1;
    }
    six->n = 6;
    six->left = NULL;
    six->right = NULL;
    
    node* nine = malloc(sizeof(node));
    if (nine == NULL)
    {
        printf("Out of memory!\n");
        return 1;
    }
    nine->n = 9;
    nine->left = NULL;
    nine->right = NULL;

    // link together nodes
    root->left = three;
    root->right = nine;
    three->right = six; 
    
    // testing insert
    for(int i = 0; i < 10; i++)
    {
        printf("Inserting %i ...%s!\n", i, insert(i)? "success" : "fail");
    }
    for(int i = 0; i < 10; i++)
    {
        printf("Tree contains %i? %s\n", i, search(root, i)? "true" : "false");
    }
    
    return 0;
}
