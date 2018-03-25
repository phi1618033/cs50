/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <math.h>
#include <stdio.h>

// global constants
const int BASE = 10;
const int MAX_KEY_LENGTH = 5;
const int CAPACITY = 65536;

// a queue
typedef struct
{
    // the index of the first element in the queue
    int head;

    // storage for the elements in the queue
    int numbers[CAPACITY];

    // the size of the queue
    int size;
}
queue;

// an array of queues
queue queues[BASE];

/*
* Initialize the global array of queues.
*/
void initialize()
{
    for(int i = 0; i < BASE; i++)
    {
        queue q;
        q.head = 0;
        q.size = 0;
        queues[i] = q;
    }
}

/**
 * Puts a new element into the queue into the "end" of the data structure
 * so that it will be retrived after the other elements already in the
 * queue.
 */
bool enqueue(int index, int number)
{
    // check that there is available space
    if(queues[index].size >= CAPACITY)
        return false;

    // insert element
    queues[index].numbers[((queues[index].head + queues[index].size) % CAPACITY)] = number;
    // increase length of queue
    ++queues[index].size;
    return true;
}

/**
 * Retrieves ("dequeues") the first element in the queue, following the
 * the "first-in, first-out" (FIFO) ordering of the data structure.
 * Reduces the size of the queue and adjusts the head to the next element.
 */
int dequeue(int index)
{
    // check that queue is not empty
    if(queues[index].size <= 0)
        return INT_MAX;
    // decrement queue length
    --queues[index].size;
    int number = queues[index].numbers[queues[index].head];
    // move head accordingly
    ++queues[index].head;
    queues[index].head %= CAPACITY;
    // return string
    return number;
}

/*
* Dequeues all elements in array of queues to output array in ascending 
* order.
*/
void dequeue_all(int* output)
{
    for(int i = 0, j = 0; i < BASE; i++)
    {
        while((output[j] = dequeue(i)) != INT_MAX)
            j++;
    }
}

/*
* Get the digit at place p in number.
*/
int get_digit(int number, int p)
{
    int digit = number / (int)pow(10, p);
    digit %= 10;
    return digit;
}

/**
 * Returns true if value is in array of n values, else false.
 * Binary search algorithm implementation (dataset is already sorted).
 */
bool search(int value, int values[], int n)
{
    int mid, min, max;
    min = 0;
    max = n - 1;
    bool found = false;
    do
    {
        // split dataset in two
        mid = (min + max)/2;
        // if value is in the left half
        if(value < values[mid])
            max = mid;
        // if value is in the right half
        if(value > values[mid])
            min = mid + 1;
        // jackpot !
        if(value == values[mid])
        {
            found = true;
            break;
        }
    }
    // do that while min < max
    while(min < max);
    return found;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int* array = values;
    for(int i = 0; i < MAX_KEY_LENGTH; i++)
    {
        initialize();
        for(int j = 0; j < n; j++)
        {
            int d = get_digit(array[j], i);
            enqueue(d, array[j]);
        }
        dequeue_all(array);
    }
    values = array;
}
