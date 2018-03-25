/**
* quicksort.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Implementations of the quick sort algorithm. WC: n^2, BC: nlogn.
**/

#include <stdio.h>

#define SIZE 7
#define TRUE 1
#define FALSE 0

// Prototypes declarations
void quicksort(int list[], int lo, int hi);
int partition(int list[], int lo, int hi);

// Utility functions
void swap(int list[], int a, int b)
{
    int temp = list[a];
    list[a] = list[b];
    list[b] = temp;
}

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
    int list[SIZE] = {6, 9, 5, 3, 2, 7, 3};

    quicksort(list, 0, SIZE-1);

    print(list, SIZE);

    return 0;
}

void quicksort(int list[], int lo, int hi)
{
    int mid;
    if(lo < hi)
    {
        mid = partition(list, lo, hi);
        quicksort(list, lo, mid);
        quicksort(list, mid + 1, hi);
    }
}

int partition(int list[], int lo, int hi)
{
    int pivot = list[lo];
    int i = lo - 1;
    int j = hi + 1;
    while(TRUE)
    {
        do
        {
            i = i + 1;
        }
        while (list[i] < pivot);
        
        do
        {
            j = j - 1;
        }
        while (list[j] > pivot);
        
        if(i >= j)
            return j;
        
        swap(list, i, j);
    }
}