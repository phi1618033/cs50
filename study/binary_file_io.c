/**
* binary_file_io.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Implement binary I/O on file.
**/

#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "binaryfile"

typedef struct persons
{
    int ssn;
    char* name;
} person;

void write()
{
    FILE* file;
    file = fopen(FILE_NAME, "wb");
    if(file == NULL)
        return;
    person p;
    p.ssn = 357;
    p.name = "Cheick Ali M. DIALLO";
    fwrite(p.name, sizeof(p.name), sizeof(p.name)/sizeof(p.name[0]), file);
    fclose(file);
}

void read()
{
    FILE* file;
    file = fopen(FILE_NAME, "rb");
    if(file == NULL)
        return;
    char* name = malloc(sizeof(char) * 128);
    fread(name, sizeof(name), sizeof(name)/sizeof(name[0]), file);
    printf("%s\n", name);

    fclose(file);
    free(name);
}

int main (void)
{
    read();
}