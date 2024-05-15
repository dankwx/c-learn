#include <stdio.h>

int main()
{
    int numero = 2;
    int numeroInput;

    printf("De 1 a 4, tente advinhar o numero certo:\n");
    scanf("%d", &numeroInput);

    if (numeroInput == numero)
    {
        printf("Voce acertou!");
    }
    else
    {
        printf("Voce errou :(");
    }

    return 0;
}