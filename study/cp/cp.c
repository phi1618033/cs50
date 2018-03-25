/**
* echo.c
*
* Cheick Ali M. DIALLO
* cheickalimdiallo@gmail.com
*
* Implementation of cp source-file destination-file which copies the content of the source-file to the destination-file.
**/

#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Usage: cp source dest\n");
        return 1;
    }

    // open up the source file
    FILE* source = fopen(argv[1], "r");
    if(source == NULL)
    {
        printf("Can't read source file !\n");
        return 1;
    }

    // now open up the destination file
    FILE* dest = fopen(argv[2], "w");
    if(dest == NULL)
    {
        printf("Can't write to destination file !\n");
        return 1;
    }

    // read the contents of the source file one char (int!) at a time
    char c;
    while((c = fgetc(source)) != EOF)
        fputc(c, dest);

        // write the character to the destination file!

    // you leak memory if you forget to close!
    fclose(source);
    fclose(dest);
}
