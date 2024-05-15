#include <stdio.h>

void menu()
{
    int opcao;
    printf("\n");
    printf("Escolha sua opcao:\n");
    printf("1. Listar\n");
    printf("2. Adicionar\n");
    printf("3. Remover\n");
    printf("4. Sair\n");
    printf("\n");
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        printf("Daniel\n");
        printf("Carl\n");
        printf("Mel\n");
        menu();
        break;
    case 2:
        printf("Adicionado!");
        menu();
        break;
    case 3:
        printf("Removido!");
        menu();
        break;
    case 4:
        printf("Até mais!");
        opcao = 4;
        break;

    default:
        break;
    }
}

int main()
{
    menu();
    return 0;
}