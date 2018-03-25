/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Swaps two values with an array.
 */
void swap(int values[], int a, int b)
{
    int temp = values[a];
    values[a] = values[b];
    values[b] = temp;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int mid, min, max;
    min = 0;
    max = n - 1;
    bool found = false;
    do
    {
        mid = (min + max)/2;
        if(value < values[mid])
            max = mid;
        if(value > values[mid])
            min = mid + 1;
        if(value == values[mid])
        {
            found = true;
            break;
        }
    }
    while(min < max);
    return found;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    bool swapped;
    do
    {
        swapped = false;
        for(int i = 0; i < n-1; ++i)
        {
            if(values[i] > values[i+1])
            {
                swap(values, i, i+1);
                swapped = true;
            }
        }
    }
    while(swapped);
    return;
}