/**
* selectionsort.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Implementations of the selection sort algorithm. WC: n^2, BC: n^2.
* Concept: Finding the smallest element and placing it at it right position.
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
    short min, count, temp;
    count = size-1;

    // for each element in the list
    for(short i = 0; i < count; ++i)
    {
        // pick the current i element as the smallest then
        min = i;
        // for each element after i
        for(short j = i+1; j <= count; ++j)
        {
            if(list[min] > list[j])
                min = j;
        }
        // if a number is smaller than min, swap them
        if(min != i)
        {
            temp = list[min];
            list[min] = list[i];
            list[i] = temp;
        }

        print(list, size);
    }
}