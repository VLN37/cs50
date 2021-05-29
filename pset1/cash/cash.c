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
    int converted = round(input * 100);


    // declaration
    int quarterchange = (converted % 25);
    int nickelchange = (quarterchange % 10);
    int dimechange = (nickelchange % 5);

    //calculate minimum number of coins in the change

    quarter = (converted / 25);
    if(quarterchange > 0)
    {
        nickel = (quarterchange / 10);
        if(nickelchange > 0)
        {
            dime = (nickelchange / 5);
            if(dimechange > 0)
            {
                cent = (dimechange / 1);
            }
        }
    }
    //print the minimum number of coins
    int change = (quarter + nickel + dime + cent);
    printf("%i\n", change);
}