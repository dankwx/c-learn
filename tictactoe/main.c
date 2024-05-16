#include <stdio.h>

int opcaoLinhaF()
{
    int opcao;
    printf("\nQual Sua Jogada?\n");
    printf("1. Linha de Cima\n");
    printf("2. Linha do Meio\n");
    printf("3. Linha de Baixo\n");
    scanf("%d", &opcao);

    return opcao;
}

int opcaoPosicaoF()
{
    int opcao;
    printf("\nQual Sua Jogada?\n");
    printf("1. Posicao Esquerdda\n");
    printf("2. Posicao Meio\n");
    printf("3. Posicao Direita\n");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        opcao = 0;
    }
    else if (opcao == 2)
    {
        opcao = 4;
    }
    else if (opcao == 3)
    {
        opcao = 8;
    }

    return opcao;
}

int main()
{
    int opcaoLinha;
    int opcaoPosicao;
    // 0 4 8
    char linhaTopo[] = {'y', ' ', '|', ' ', 'y', ' ', '|', ' ', 'y', '\0'};
    char linhaTopoRef[] = {'y', ' ', '|', ' ', 'y', ' ', '|', ' ', 'y', '\0'};
    char linhaMeio[] = {'y', ' ', '|', ' ', 'y', ' ', '|', ' ', 'y', '\0'};
    char linhaMeioRef[] = {'y', ' ', '|', ' ', 'y', ' ', '|', ' ', 'y', '\0'};
    char linhaBaixo[] = {'y', ' ', '|', ' ', 'y', ' ', '|', ' ', 'y', '\0'};
    char linhaBaixoRef[] = {'y', ' ', '|', ' ', 'y', ' ', '|', ' ', 'y', '\0'};

    while (1)
    {
        printf("%s\n", linhaTopo);
        printf("%s\n", linhaMeio);
        printf("%s\n", linhaBaixo);
        opcaoLinha = opcaoLinhaF();
        opcaoPosicao = opcaoPosicaoF();

        switch (opcaoLinha)
        {
        case 1:
            if (linhaTopo[opcaoPosicao] == linhaTopoRef[opcaoPosicao])
            {
                linhaTopo[opcaoPosicao] = 'x';
                break;
            }

            printf("nao daaaaa");
            break;
        case 2:
            if (linhaMeio[opcaoPosicao] == linhaMeioRef[opcaoPosicao])
            {
                linhaMeio[opcaoPosicao] = 'x';
                break;
            }
            printf("nao daaaaa");
            break;

            linhaMeio[opcaoPosicao] = 'x';
            break;
        case 3:
            if (linhaBaixo[opcaoPosicao] == linhaBaixoRef[opcaoPosicao])
            {
                linhaBaixo[opcaoPosicao] = 'x';
                break;
            }
            printf("nao daaaaa");
            break;

            linhaBaixo[opcaoPosicao] = 'x';
            break;

        default:
            break;
        }
    }

    return 0;
}