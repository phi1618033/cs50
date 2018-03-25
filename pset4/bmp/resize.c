/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resizes 24-bit uncompressed BMPs by a factor of n.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }

    // check factor range
    int n = atoi(argv[1]);
    if(n < 1 || n > 100)
    {
        printf("Factor range is 1 to 100 included\n");
        return -1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // update header information for output file
    BITMAPINFOHEADER bio;
    bio = bi;
    bio.biWidth = bio.biWidth * n;
    bio.biHeight = bio.biHeight * n;

        // determine outpads for outfile scanlines
    int outpads = (4 - (bio.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bio.biSizeImage = ((bio.biWidth * sizeof(RGBTRIPLE)) + outpads) * abs(bio.biHeight);

    BITMAPFILEHEADER bfo;
    bfo = bf;
    bfo.bfSize = bio.biSizeImage + 14 + 40;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bfo, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bio, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine inpads for infile scanlines
    int inpads =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    int widthset = bi.biWidth * sizeof(RGBTRIPLE);
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {

        // resize vertically
        for(int l = 0; l < n; ++l)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile - resize horizontally
                for(int m = 0; m < n; ++m)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over inpads, if any
            fseek(inptr, inpads, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < outpads; k++)
            {
                fputc(0x00, outptr);
            }

            // go back to the start of the row
            if(l < n-1)
            {
                fseek(inptr, -(widthset + inpads), SEEK_CUR);
            }
        }
        
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
