/**
* binarysearch.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Implementations of the binary search algorithm. WC: logn, BC: 1.
* Concept: works on a sorted list by recursively dividing the list in 2.
**/

#include <stdio.h>

#define UNUSED(x) (void)(x)

#define SIZE 35
#define TRUE 1
#define FALSE 0

// Prototypes declarations
void search(int y, int list[], int min, int max);
void sort(int list[], int size);

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

    sort(list, SIZE);
    printlist(list, SIZE);
    search(90, list, 0, SIZE-1);

    return 0;
}

void search(int y, int list[], int min, int max)
{
    int found = FALSE;
    int mid;

    do
    {
        mid = (min + max)/2;

        if(y < list[mid])
            max = mid;
        if(y > list[mid])
            min = mid + 1;
        if(y == list[mid])
        {
            found = TRUE;
            break;
        }
    }
    while(min < max);

    if(found)
        printf("found\n");
    else
        printf("not found\n");

}

void sort(int list[], int size)
{
    short swapped, count, temp;
    count = size-1;

    do
    {
        swapped = FALSE;
        for(short i=0; i<count; ++i)
        {
            if(list[i]>list[i+1])
            {
                temp = list[i];
                list[i] = list[i+1];
                list[i+1] = temp;
                swapped = TRUE;
            }
        }
    }
    while(swapped);
}
