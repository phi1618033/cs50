/***************************************************************************
* queue_structure_int.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* A radix sort algorithm implementation with an array of queues.
***************************************************************************/

// for strdup() in the testing code
#define _XOPEN_SOURCE 500

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

// the capacity of the queue
const int CAPACITY = 10;

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

// declare a queue (as a global variable)
queue q;

/**
 * Puts a new element into the queue into the "end" of the data structure
 * so that it will be retrived after the other elements already in the
 * queue.
 */
bool enqueue(int number)
{
    // check that there is available space
    if(q.size >= CAPACITY)
        return false;
    // insert element
    q.numbers[((q.head + q.size) % CAPACITY)] = number;
    // increase length of queue
    ++q.size;
    return true;
}

/**
 * Retrieves ("dequeues") the first element in the queue, following the
 * the "first-in, first-out" (FIFO) ordering of the data structure.
 * Reduces the size of the queue and adjusts the head to the next element.
 */
int dequeue(void)
{
    // check that queue is not empty
    if(q.size <= 0)
        return INT_MAX;
    // decrement queue length
    --q.size;
    int number = q.numbers[q.head];
    // move head accordingly
    ++q.head;
    q.head %= CAPACITY;
    // return string
    return number;
}

/**
 * Implements some simple test code for our queue
 */
int main(void)
{
    // initialize the queue
    q.head = 0;
    q.size = 0;

    printf("Enqueueing %i integers...", CAPACITY);
    for (int i = 0; i < CAPACITY; i++)
    {
        enqueue(CAPACITY + i);
    }
    printf("done!\n");

    printf("Making sure that the queue size is indeed %i...", CAPACITY);
    assert(q.size == CAPACITY);
    printf("good!\n");

    printf("Making sure that enqueue() now returns false...");
    assert(!enqueue(123));
    printf("good!\n");

    printf("Dequeueing everything...");
    int int_array[CAPACITY];
    for (int i = 0; i < CAPACITY; i++)
    {
        int_array[i] = dequeue();
        printf("%d ", int_array[i]);
    }
    printf("done!\n");

    printf("Making sure that the queue is now empty...");
    assert(q.size == 0);
    printf("good!\n");

    printf("Making sure that dequeue() now returns NULL...");
    assert(dequeue() == INT_MAX);
    printf("good!\n");

    printf("Making sure that the head wraps around appropriately...");
    for (int i = 0; i < CAPACITY; i++)
    {
        assert(enqueue(50));
    }

    // to make sure that they adjust the head pointer appropriately, we'll
    // enqueue and dequeue a bunch of times to make sure they don't just
    // walk off the end of the char* strings[] array
    for (int i = 0; i < CAPACITY * 10; i++)
    {
        for (int j = 0; j < CAPACITY / 2; j++)
        {
            assert(dequeue());
        }
        for (int j = 0; j < CAPACITY / 2; j++)
        {
            assert(enqueue(50));
        }
    }
    printf("good!\n");

    printf("\n********\nSuccess!\n********\n");

    return 0;
}
