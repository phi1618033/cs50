/**
* dictionary.c
*
* Computer Science 50
* Problem Set 5
*
* Implements a dictionary's functionality.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

#include "dictionary.h"

#define UNUSED(x) (void)(x)

// defines
#define MAX_WORD_LENGTH LENGTH+1
// hash table size = base size * 0.75 
// if size is not a prime number, take the next prime number
#define SHELF_SIZE 250423

// typedefs
typedef struct node_type
{
	char* data;
	struct node_type* next;
}
node;

typedef uint32_t DWORD;
typedef uint16_t WORD;

// global variables
FILE* file;
node* shelf[SHELF_SIZE] = { NULL };
unsigned shelf_words_count = 0;
unsigned shelf_words_collisions_count = 0;

// utility functions
/**
* Returns total number of collisions.
*/
unsigned number_of_collisions()
{
	return shelf_words_collisions_count;
}

/**
* Display shelf content.
*/
void display_shelf()
{
	node* row = NULL;
	printf("*******Dictionary*******\n");
	for (int i = 0; i < SHELF_SIZE; ++i)
	{
		row = shelf[i];
		if(row != NULL)
		{
			printf("%d : ", i);
			while(row != NULL)
			{
				printf("%s ", row->data);
				row = row->next;
			}
		}
		else
			printf("%d : NULL", i);
		printf("\n");
	}
	printf("************************\n");
}

/**
* Computes hash value from hash key.
*/
unsigned hash_simply(const char* key, size_t wrdlen)
{
	unsigned sum = 0;
	while(*key != 0)
	{
		sum += *key;
		++key;
	}
	return sum % SHELF_SIZE;
}

/**
* FNV1A hash function from Georgi at http://encode.ru/threads/612-Fastest-decompressor!?p=22184&viewfull=1#post22184
*/
unsigned FNV1A_Hash_WHIZ(const char *str, size_t wrdlen)
{
    const unsigned PRIME = 1607;
    unsigned hash32 = 2166136261;
    const char *p = str;
 
    for(; wrdlen >= sizeof(DWORD); wrdlen -= sizeof(DWORD), p += sizeof(DWORD)) {
        hash32 = (hash32 ^ *(DWORD *)p) * PRIME;
    }
    if (wrdlen & sizeof(WORD)) {
        hash32 = (hash32 ^ *(WORD*)p) * PRIME;
        p += sizeof(WORD);
    }
    if (wrdlen & 1) 
        hash32 = (hash32 ^ *p) * PRIME;
    return (hash32 ^ (hash32 >> 16)) % SHELF_SIZE;
}

/**
* Adds word to shelf based on hash value
*/
void add_to_shelf(unsigned value, char* word)
{
	// get row in shelf
	node* row = shelf[value];
	// create new node for row
	node* new = malloc(sizeof(node));
	if(new == NULL)
		return;
	new->data = malloc(sizeof(char) * MAX_WORD_LENGTH);
	strncpy(new->data, word, strlen(word));

	// insert node into row
	if(row == NULL)
	{
		// first node in row
		new->next = NULL;
		row = new;
	}
	else
	{
		// nth node in row, collision
		new->next = row;
		row = new;
		++shelf_words_collisions_count;
	}
	shelf[value] = row;
	++shelf_words_count;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
	bool return_flag = false;
	// get word length
    unsigned word_length = strlen(word);
    char* wrd = malloc(sizeof(char) * (word_length + 1));
    if(wrd != NULL)
    {
    	strcpy(wrd, word);
	    // make word lower case only
	    unsigned short c = 0;
		while (wrd[c] != '\0') {
		  if (wrd[c] >= 'A' && wrd[c] <= 'Z')
		     wrd[c] = wrd[c] + 32;
		  c++;
		}
	    // get word's hash value
	    unsigned value = FNV1A_Hash_WHIZ(wrd, word_length);
	    // search for word in corresponding row of shelf
	    node* row = shelf[value];
	    while(row != NULL)
	    {
	    	if(strcmp(row->data, wrd) == 0)
    		{
    			return_flag = true;
    			break;
    		}
	    	row = row->next;
	    }
	    free(wrd);
    }
    return return_flag;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
	// open dictionary file for reading
    file = fopen(dictionary, "r");
    if(file == NULL)
    {
    	printf("Could not open dictionary file !\n");
    	return false;
    }

    char word[MAX_WORD_LENGTH];
    // read words in file
    while(fscanf(file, "%s", word) != EOF)
    {
    	// compute word's hash value
    	unsigned value = FNV1A_Hash_WHIZ(word, strlen(word));
    	// add word to hash table
    	add_to_shelf(value, word);
    }
    fclose(file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return shelf_words_count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    node* row = NULL;
    char* temp_data = NULL;
    node* temp_node = NULL;
	for (int i = 0; i < SHELF_SIZE; ++i)
	{
		row = shelf[i];
		while(row != NULL)
		{
			temp_node = row;
			temp_data = row->data;
			row = row->next;
			free(temp_data);
			free(temp_node);
		}
	}
    return true;
}
