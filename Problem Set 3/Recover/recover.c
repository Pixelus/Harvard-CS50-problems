/* Program that recovers JPEGs from a forensic image. */

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return 1;
    }
    
    // Open memory card file entered into argument with the command line
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }
    
    // Create a new JPG for recovering image
    FILE *img = NULL;
    
    // Create buffer, filename array, counter and flag
    unsigned char buffer[512];
    char filename[8];
    int counter = 0;
    bool flag = false;
    
    // Read the file until the end of memory card (read 512MB block into a buffer)
    while (fread(buffer, 512, 1, file) != 0)
    {
        // Check if a new JPEG starts
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the current JPEG file for start to read the next
            if (flag == true)
            {
                fclose(img);
            }
            // If a JPEG file is found
            else
            {
                flag = true;
            }
            
            // Making a new JPEG with a filename like ###.jpg
            sprintf(filename, "%03i.jpg", counter);
            // Open a new JPG 
            img = fopen(filename, "w");
            // Keep track of number file
            counter++;
        }
        
        // Until a new JPEG is found 
        if (flag == true)
        {
            // Write 512 bytes
            fwrite(&buffer, 512, 1, img);
        }
    }
    
    // Close infile and outfile
    fclose(file);
    fclose(img);

    // Success
    return 0;
}
