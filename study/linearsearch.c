/**
* linearsearch.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Implementations of the linear search algorithm.
**/

#include <stdio.h>

#define SIZE 35
#define TRUE 1
#define FALSE 0

// Prototypes declarations
void search(int y, int list[], int size);

// Utility functions
void swap(int list[], int a, int b)
{
    int temp = list[a];
    list[a] = list[b];
    list[b] = temp;
}

void printlist(int list[], int size)
{
    for(int i=0; i<size; ++i)
    {
        printf(" %d ", list[i]);
    }
    printf("\n");
}

int main(void)
{
    int list[SIZE] = {287, 488, 262, 727, 548, 349, 735, 69, 439, 83, 696, 104, 90, 275, 374, 596, 626, 438, 490, 568, 535, 273, 160, 677, 209, 352, 396, 61, 481, 71, 590, 297, 294, 298, 147};

    search(357, list, SIZE);

    return 0;
}

void search(int y, int list[], int size)
{
    int found = FALSE;
    for (int i = 0; i < size; ++i)
    {
        if(list[i] == y)
            found = TRUE;
    }
    if(found)
        printf("%d found\n", y);
    else
        printf("%d not found\n", y);
}