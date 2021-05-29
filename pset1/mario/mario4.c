#include <stdio.h>
#include <cs50.h>

char hash = 35;
char space = 20;
int height;

int main(void)

// inquire user for height between 1 and 8
{
    do
    {
        height = get_int("Pyramid height\n");
    }
    while (height < 1 || height > 8);
    
    

    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y <= x; y++)
        {
            printf("#");
        }
        printf("\n");
    }
}
