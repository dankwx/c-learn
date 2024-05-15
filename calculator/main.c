#include <stdio.h>

void calculadora();
void continuarCalculadora();

void continuarCalculadora()
{
    int opcao;

    printf("Deseja continuar?\n");
    printf("1. Sim\n");
    printf("2. Nao\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        calculadora();
        break;
    case 2:
        printf("Ate depois :)\n");
        break;

    default:
        printf("Selecione uma opcao valida.\n");
        continuarCalculadora();
        break;
    }
}

void calculadora()
{
    int numeroUm;
    int numeroDois;
    int opcao;
    printf("Que operacao matematica deseja realizar?\n");

    printf("1. Soma\n");
    printf("2. Subtracao\n");
    printf("3. Multiplicacao\n");
    printf("4. Divisao\n");
    printf("5. Sair\n");

    scanf("%d", &opcao);
    if (opcao == 5)
    {
        printf("Ate depois :)\n");
        return;
    }
    else if (opcao > 5 || opcao <= 0)
    {
        printf("Escolha invalida.\n");
        calculadora();
    }

    else
    {
        printf("Insira o primeiro numero: \n");
        scanf("%d", &numeroUm);
        printf("Insira o segundo numero: \n");
        scanf("%d", &numeroDois);
        switch (opcao)
        {
        case 1:
            printf("O resultado da soma e: %d\n", numeroUm + numeroDois);
            continuarCalculadora();
            break;
        case 2:
            printf("O resultado da subtracao e: %d\n", numeroUm - numeroDois);
            continuarCalculadora();
            break;
        case 3:
            printf("O resultado da multiplicacao e: %d\n", numeroUm * numeroDois);
            continuarCalculadora();
            break;
        case 4:
            printf("O resultado da divisao e: %d\n", numeroUm / numeroDois);
            continuarCalculadora();
            break;
        default:
            break;
        }
    }
}

int main()
{
    calculadora();
    return 0;
}