// 0 - ensure proper usage

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
unsigned long int filesize;
FILE *out = NULL;
char filename[8];


int main(int argc, char *argv[])
{
    //ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    //check if card is null
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 2;
    }

    //initialization
    fopen(argv[1], "r");
    int filenumber = 1;
    int filecounter = 0;
    BYTE buffer[511];

    //read until the first signature
    while(1)
    {
        fread(buffer, 1, 512, card);
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            break;
    }

    //write until EOF
    do
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%.3i.jpg", filecounter);
            out = fopen(filename, "w");
            filecounter++;
            fwrite(buffer, 1, 512, out);
            while(1)
            {
                f
                d(buffer, 1, 512, card);
                if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
                {
                    fclose(out);
                    break;
                }
                else if(feof(card))
                {
                    fclose(out);
                    break;
                }
                else
                    fwrite(buffer, 1, 512, out);
            }
        }
    }
    while(!feof(card));
    fclose(out);
    return 0;
}
