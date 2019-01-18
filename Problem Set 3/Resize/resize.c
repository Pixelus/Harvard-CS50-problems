/* Program that inputs a bitmap (copies a BMP file) and creates an outfile that scales */
/* that bitmap by a user-given number. */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s scale infile outfile\n", argv[0]);
        return 1;
    }

    // Remember filenames and turn scale into integer
    int scale = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // Ensure scale argument, a positive integer less than or equal to 100
    if (scale < 0 || scale > 100)
    {
        fprintf(stderr, "Usage: %s scale infile outfile\n", argv[0]);  
        return 1; 
    }

    // Open input and output files
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // Read infile's BITMAPFILEHEADER and infile's BITMAPINFOHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Update outfile's header with new dimensions because a new bitmap file involves new header info
    BITMAPFILEHEADER out_bf = bf;
    BITMAPINFOHEADER out_bi = bi;
    // Width (doesn't include padding) and height of image
    out_bi.biWidth *= scale;
    out_bi.biHeight *= scale;

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Determine and update padding for scanlines (rows), if number of pixels isn't a multiple of 4 add padding (0x00)
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int out_padding = (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // Update outfile's header with new total size of image (include pixels and padding) and
    // new total size of file (include pixels, padding and headers)
    out_bi.biSizeImage = ((sizeof(RGBTRIPLE) * out_bi.biWidth) + out_padding) * abs(out_bi.biHeight);
    out_bf.bfSize = out_bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // Write header info outfile's BITMAPFILEHEADER and BITMAPINFOHEADER
    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Read infile's (iterate over) scanlines (rows) pixel by pixel
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // Read each scanline scale times
        for (int j = 0; j < scale; j++)
        {
            // Iterate over pixels in scanline
            for (int k = 0; k < bi.biWidth; k++)
            {
                // Temporary storage
                RGBTRIPLE triple;

                // Read RGB triple from infile and write RGB triple to outfile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                // Write RBG triple to outfile, multiplied by scale
                for (int l = 0; l < scale; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            // Writing a new padding in outfile
            for (int m = 0; m < out_padding; m++)
            {
                fputc(0x00, outptr);    
            }

            // Return to the beginning of a scanline
            if (j < scale - 1)
            {
                fseek(inptr, -bi.biWidth * sizeof(RGBTRIPLE), SEEK_CUR);    
            }
        }
        // Skip over padding if any in infile
        fseek(inptr, padding, SEEK_CUR);
    }
    
    // Close infile and outfile
    fclose(inptr);
    fclose(outptr);

    // Success
    return 0;
}
