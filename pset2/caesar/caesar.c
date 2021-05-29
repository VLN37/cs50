#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

// implement a program that accepts argument count == 1 otherwise break
// 1 - read the input and return it
// 2 - convert the input into an integer via atoi
// 3 - try to shift all characters in the argument by +1
// 4 - implement the change to the actual key, ignoring non alphabetical values
// 5 - implement conversion into a rotating cipher rather than key + ascii

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

    string s = get_string ("plaintext: ");
    printf("ciphertext: ");

    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {

        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", (s[i]+k-97)%26 +97);
        }

        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            printf("%c", (s[i]+k-65)%26 +65);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}