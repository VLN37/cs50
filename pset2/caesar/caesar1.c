#include <stdio.h>
#include <cs50.h>

// implement a program that accepts argument count == 1 otherwise break
// 1 - read the input and return it

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
        printf ("%s \n", argv[1]);
    }
}