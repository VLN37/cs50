#include <stdio.h>
#include <cs50.h>

int main(void)

// inquire user for height between 1 and 8
{
    int height;
    do
    {
        height = get_int("Pyramid height\n");
    }
    while (height < 1 || height > 8);
}
