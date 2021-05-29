#include <stdio.h>
#include <cs50.h>


int main(void)

// if n is 1 stop
// if n is even - n/2
// if n is odd - 3n + 1
// return the number of iterations needed to finish the sequence


{
    int counter = 0;
    int n = get_int("n: ");

    while(n != 1)
    {
        if(n == 1)
            return 1;
        else if(n % 2 == 0)
        {
            n = n / 2;
            counter ++;
        }
        else
        {
            n = 3 * n + 1;
            counter++;
        }
    }
    printf("Number of steps in the sequence: %i\n", counter);
}