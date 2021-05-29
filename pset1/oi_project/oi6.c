#include <stdio.h>
#include <cs50.h>
#include <string.h>

void lala(void);
int main(void)
{
    string name = get_string("Como você chama?\n");
    {
        if (strcmp(name, "Lala") == 0) // como checar duas vezes sem dar ctrl c+v? (name, "Lala" || "lala")
        {
            printf("Oi, %s. Te amo!\n", name);
        }
        else if (strcmp(name, "Pedro") == 0)
        {
            printf("Eaí, %s. De boas?\n", name);
        }
        else
        {
            printf("Oi, %s.\n", name);
        }
    }

}
