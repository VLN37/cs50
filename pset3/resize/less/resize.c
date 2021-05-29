// 0 - calculates the bfsize of the resized file
// 1 - implement a way to print pixels n times horizontally
// 2 - implement a way to print pixels n times vertically by iterating and adding fseek back

// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "bmp.h"

int atoitest;
unsigned int n;

int main(int argc, char *argv[])
{

    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resizeint infile outfile\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if ((isdigit(argv[1][i]) == 0))
        {
            fprintf(stderr, "Usage: resizeint infile outfile\n");
            return 1;
        }
    }
    atoitest = atoi(argv[1]);
    if ((atoitest < 1) || (atoitest > 100))
    {
        fprintf(stderr, "Usage: resizeint infile outfile\n");
        return 1;
    }

    n = atoi(argv[1]);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }


    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    BITMAPFILEHEADER bf2;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    BITMAPINFOHEADER bi2;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    //***************************************************************************************
    bf2 = bf;
    bi2 = bi;
    bi2.biHeight *= n;
    bi2.biWidth *= n;
    int padding2 = (4 - (bi2.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi2.biSizeImage = (3 * (abs(bi2.biHeight) * bi2.biWidth)) + (padding2 * abs(bi2.biHeight));
    bf2.bfSize = bi2.biSizeImage + bf2.bfOffBits;


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }



    // write outfile's BITMAPFILEHEADER
    fwrite(&bf2, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi2, sizeof(BITMAPINFOHEADER), 1, outptr);


    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    //***************************************************************************************


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        for (int vertical = 0; vertical < n; vertical ++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                //**********************************************************************************
                for (int l = 0; l < n; l++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < padding2; k++)
            {
                fputc(0x00, outptr);
            }
            if (vertical < n - 1)
            {
                fseek(inptr, - (padding + (bi.biWidth * sizeof(RGBTRIPLE))), SEEK_CUR);
            }

        }

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
