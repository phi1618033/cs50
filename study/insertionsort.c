/**
* insertionsort.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Implementations of the insertion sort algorithm. WC: n^2, BC: n.
* Concept: Inserting each element at its correct position by shifting other elements.
**/

#include <stdio.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

void sort(int* list, int size);

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

void sort(int* list, int size)
{
    // for each element from the first
    for(int i = 1; i < size; i++)
    {
        // pick element to position
        int element = list[i];
        int j = i;
        // compare elements up the list and shift those greater than the element
        while(j > 0 && list[j-1] > element)
        {
            printf("%d shifted\n", list[j-1]);
            list[j] = list[j-1];
            j--;
        }
        // insert element at it correct position in the list
        list[j] = element;
        print(list, size);
    }
}