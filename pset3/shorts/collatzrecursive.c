#include <stdio.h>
#include <cs50.h>


int main(void)

// if n is 1 stop
// if n is even - n/2
// if n is odd - 3n + 1
// return the number of iterations needed to finish the sequence


int collatz (int n)
{
    int n = get_int("n: ");
        if(n == 1)
            return 0;
        else if(n % 2 == 0)
            return 1 + collatz (n / 2)
        else
            return 1 + collatz (n * 3 + 1)

    printf("Number of steps in the sequence: %i\n", counter);
}