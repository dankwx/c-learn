#include <stdio.h>

int main()
{
    int opcao;
    printf("Insira a opcao desejada:\n");
    printf("1. Palavra\n");
    printf("2. Frase\n");
    printf("3. Numero\n");
    printf("Sair\n");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        printf("Jardim");
    }
    else if (opcao == 2)
    {
        printf("O Jardim esta belo.");
    }
    else if (opcao == 3)

    {
        printf("357");
    }
    else if (opcao == 4)
    {
        printf("Tchau, ate mais ;)");
    }
    else
    {
        printf("Opcao invalida.");
    }

    return 0;
}