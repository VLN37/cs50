#include <stdio.h>
#include <cs50.h>

// implement a program that accepts argument count == 1 otherwise break

int main (int argc, string argv[])

{
    while (argc != 2)
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }
    if (argc == 2)
    {
        printf ("Success!\n");
    }
}
