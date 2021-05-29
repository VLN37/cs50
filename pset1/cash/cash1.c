#include <stdio.h>
#include <cs50.h>
#include <math.h>

int cent;
int nickel;
int dime;
int quarter;


int main(void)

{
    // ask user for input
    float input;
    do
    {
        input = get_float ("Change: ");
    }
    while (input<=0);

    // convert input into integer
    int converted = (input * 100);
    printf ("%i\n", converted);

    //calculate minimum number of coins in the change
    {
         while(converted > 25)
        {
            quarter = (converted / 25);
        }
    }
    printf("%i\n", quarter);
}