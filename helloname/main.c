#include <stdio.h>

int main()
{
    char nomeCompleto[30];
    printf("Insira seu nome completo:\n");
    fgets(nomeCompleto, sizeof(nomeCompleto), stdin);
    printf("Seu nome e: %s.", nomeCompleto);
    return 0;
}