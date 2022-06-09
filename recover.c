
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <unistd.h>
#include <stdint.h>

typedef uint8_t BYTE;


int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int jpeg_count = 0;
        string filename = argv[1];
        FILE *fp = fopen(filename, "r");
        FILE *img;
        BYTE buffer[512];
        char newjpeg[8];
        bool jpeg_found = false;
        bool makenew = false;

        if (fp == NULL)
        {
            printf("Error");
            return 2;
        }

        while (fread(buffer, sizeof(BYTE), 512, fp) > 0)
        {

            if (jpeg_found == true)
            {
                if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
                {
                    sprintf(newjpeg, "%03i.jpg", jpeg_count);
                    img = fopen(newjpeg, "w");
                    fwrite(buffer, sizeof(BYTE), 512, img);
                    jpeg_count++;
                }
                else
                {
                    fclose(img);
                    img = fopen(newjpeg, "a");
                    fwrite(buffer, sizeof(BYTE), 512, img);
                }
                
            }
            else if (((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0)) && jpeg_found == false)
            {
                jpeg_found = true;
                sprintf(newjpeg, "%03i.jpg", jpeg_count);
                img = fopen(newjpeg, "w");
                fwrite(buffer, sizeof(buffer), 1, img);
                jpeg_count++;
            }
        }
        fclose(fp);
        fclose(img);
        return 0;
    }
    else
    {
        printf("Usage: ./recover FILENAME\n");
        return 1;
    }

}
