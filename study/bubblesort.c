/**
* bubblesort.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Implementations of the bubble sort algorithm. WC: n^2, BC: n.
* Concept: Swapping adjacent pairs when they are out of order.
**/

#include <stdio.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

void sort(int list[], int size);

void print(int list[], int size)
{
    for(int i=0; i<size; ++i)
    {
        printf(" %d ", list[i]);
    }
    printf("\n");
}

int main(void)
{
    int list[SIZE] = {287, 488, 262, 727, 548, 349, 735, 69, 439, 83};

    sort(list, SIZE);
    print(list, SIZE);

    return 0;
}

void sort(int list[], int size)
{
    short swapped, count, temp;
    count = size-1;

    do
    {
        // if no swapping occured in the last round, then the list is sorted
        swapped = FALSE;
        // for each elements in the list
        for(short i = 0; i < count; ++i)
        {
            // compare adjacent elements
            if(list[i]>list[i+1])
            {
                // swap them if they are not in the correct order
                temp = list[i];
                list[i] = list[i+1];
                list[i+1] = temp;
                swapped = TRUE;
            }
        }
        print(list, size);
    }
    while(swapped);
}
