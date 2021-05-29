#include <stdio.h>
#include <cs50.h>
#include <string.h>

int k;

int main (int argc, string argv[])

{
    while (argc != 2)
    {
        printf ("Usage: ./caesar keyword\n");
        return 1;
    }

    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        k = argv[1][i];
        if ((k < 'A' || k > 'Z') && (k < 'a' || k > 'z'))
        {
            printf ("Usage: ./caesar keyword\n");
            return 1;
        }
    }
        printf ("Success!\n");
        printf ("%i \n", k);
}