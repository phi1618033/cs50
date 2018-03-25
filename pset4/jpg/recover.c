/**
* recover.c
*
* Computer Science 50
* Problem Set 4
*
* Recovers JPEGs from a forensic image.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// symbolic constants
#define IMAGE_NAME "card.raw"
#define BLOCK_SIZE 512

// defined types
typedef uint8_t  BYTE;

int main(void)
{
    // open image file
    FILE* image = fopen(IMAGE_NAME, "r");
    if(image == NULL)
    {
        printf("Could not open image file\n");
        return -1;
    }

    // declare image pointer - buffer
    BYTE buffer[BLOCK_SIZE];

    // number of files found
    int number = -1;

    // is jpeg file currently opened 
    bool current = false;

    // do we have a new jpeg file
    bool new = false;
    
    // is it the first jpeg file
    bool first = true;

    // jpeg file name
    char name[7];

    // jpeg file pointer
    FILE* jpeg;

    // read image
    while(fread(buffer, sizeof(BYTE), BLOCK_SIZE, image))
    {
        // check for end of file
        if(feof(image))
            break;

        // check for a jpeg signature
        if(buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && buffer[3] >= 224 && buffer[3] <= 239)
        {
            new = true;
            ++number;
        }

        // we have a new jpeg file
        if(new)
        {
            if(first)
                first = false;
            else
                fclose(jpeg);
            sprintf(name, "%03d.jpg", number);
            jpeg = fopen(name, "w");
            current = true;
            new = false;
        }

        // write to the currently opened jpeg file
        if(current)
        {
            fwrite(&buffer, sizeof(BYTE), BLOCK_SIZE, jpeg);
        }
    }
    // close the last opened jpeg file
    fclose(jpeg);

    // close image file
    fclose(image);
}
