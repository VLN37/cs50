#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// program should receive a keyword as input and output a ciphered message with each letter of input being a key
// 0 - start from caesar.c and ask for keyword input rather than key
// 2 - iterate over keyword and string to cipher the message

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
        printf ("Success!\n");
        printf ("%i \n", k);
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        printf("%c", argv[1][i]);
        int c = toupper(argv[1][i]);
        printf("%c", c);
    }
    printf("\n");

    string s = get_string ("plaintext: ");
    printf("ciphertext: ");

    int n = strlen(s);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (j > strlen(argv[1]))
        {
            j = 0;
        }

        if (s[i] >= 'a' && s[i] <= 'z')
        {
            k = toupper(argv[1][j]);
            printf("%c", (s[i]+k-97)%26 +97);
            j++;
        }

        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            k = toupper(argv[1][j]);
            printf("%c", (s[i]+k-65)%26 +65);
            j++;
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}