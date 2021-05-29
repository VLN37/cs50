#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string ("Como você chama?\n"); 
    printf("Oi, %s. Te amo!\n", name);
}
