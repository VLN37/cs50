#include <stdio.h>
#include <cs50.h>
#include <string.h>

// implement a program that accepts argument count == 1 otherwise break
// 1 - read the input and return it
// 2 - convert the input into an integer via atoi
// 3 - try to shift all characters in the argument by +1

int k;

int main (int argc, string argv[])

{
    while (argc != 2)
    {
        printf ("Usage: ./caesar key\n");
        return 1;
    }
    if (argc == 2)
    {
        k = atoi(argv[1]);
        if (k == 0)
        {
            printf ("Usage: ./caesar key\n");
            return 1;
        }
        printf ("Success!\n");
        printf ("%i \n", k);
    }

    string s = get_string ("Plaintext: ");

    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        printf("%c", s[i] + 1);
    }
    printf("\n");
}