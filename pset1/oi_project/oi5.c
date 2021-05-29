#include <stdio.h>
#include <cs50.h>
#include <string.h>

void lala(void);
int main(void)
{
    string name = get_string ("Como você chama?\n");    
    {
        if (strcmp (name, "Lala") == 0)
        {
        printf("Oi, %s. Te amo!\n", name);  
        }
        else
        {
        printf("Oi, %s.\n", name);
        }
    }

}
