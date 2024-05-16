#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

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

int todasPosicoesDiferentesTopo(char linhaTopo[], char linhaTopoRef[], int tamanho)
{
    int i = 0; // Inicializa a variável de índice
    while (i < tamanho)
    {
        if (linhaTopoRef[i] == 'y' && linhaTopo[i] == 'y')
        {
            return 0; // Encontrou uma posição onde ambas são 'y'
        }
        i++;
    }
    return 1; // Todas as posições com 'y' em linhaTopoRef são diferentes de 'y' em linhaTopo
};
int todasPosicoesDiferentesMeio(char linhaMeio[], char linhaMeioRef[], int tamanho)
{
    int i = 0; // Inicializa a variável de índice
    while (i < tamanho)
    {
        if (linhaMeioRef[i] == 'y' && linhaMeio[i] == 'y')
        {
            return 0; // Encontrou uma posição onde ambas são 'y'
        }
        i++;
    }
    return 1; // Todas as posições com 'y' em linhaTopoRef são diferentes de 'y' em linhaTopo
};
int todasPosicoesDiferentesBaixo(char linhaBaixo[], char linhaBaixoRef[], int tamanho)
{
    int i = 0; // Inicializa a variável de índice
    while (i < tamanho)
    {
        if (linhaBaixoRef[i] == 'y' && linhaBaixo[i] == 'y')
        {
            return 0; // Encontrou uma posição onde ambas são 'y'
        }
        i++;
    }
    return 1; // Todas as posições com 'y' em linhaTopoRef são diferentes de 'y' em linhaTopo
};

// verificar vitoria jogador
int verificarVitoriaJogador(char linhaTopo[], char linhaMeio[], char linhaBaixo[], int tamanho)
{
    int i = 0;
    while (i < tamanho)
    {
        // verifica vitorias verticais
        if (linhaTopo[i] == 'x' && linhaMeio[i] == 'x' && linhaBaixo[i] == 'x')
        {
            return 1;
        }
        // verifica vitorias horizontal
        else if ((linhaTopo[0] == 'x' && linhaTopo[4] == 'x' && linhaTopo[8] == 'x') || (linhaMeio[0] == 'x' && linhaMeio[4] == 'x' && linhaMeio[8] == 'x') || (linhaBaixo[0] == 'x' && linhaBaixo[4] == 'x' && linhaBaixo[8] == 'x'))
        {
            return 1;
        }
        else if ((linhaTopo[0] == 'x' && linhaMeio[4] == 'x' && linhaBaixo[8] == 'x') || (linhaBaixo[0] == 'x' && linhaMeio[4] == 'x' && linhaTopo[8] == 'x'))
        {
            return 1;
        }

        i++;
    };
    return 0;
};
// verificar vitoria IA
int verificarVitoriaIa(char linhaTopo[], char linhaMeio[], char linhaBaixo[], int tamanho)
{
    int i = 0;
    while (i < tamanho)
    {
        // verifica vitorias verticais
        if (linhaTopo[i] == 'o' && linhaMeio[i] == 'o' && linhaBaixo[i] == 'o')
        {
            return 1;
        }
        // verifica vitorias horizontal
        else if ((linhaTopo[0] == 'o' && linhaTopo[4] == 'o' && linhaTopo[8] == 'o') || (linhaMeio[0] == 'o' && linhaMeio[4] == 'o' && linhaMeio[8] == 'o') || (linhaBaixo[0] == 'o' && linhaBaixo[4] == 'o' && linhaBaixo[8] == 'o'))
        {
            return 1;
        }
        else if ((linhaTopo[0] == 'o' && linhaMeio[4] == 'o' && linhaBaixo[8] == 'o') || (linhaBaixo[0] == 'o' && linhaMeio[4] == 'o' && linhaTopo[8] == 'o'))
        {
            return 1;
        }

        i++;
    };
    return 0;
};

int main()
{
    int opcaoLinha;
    int opcaoPosicao;
    int jogoFinalizado = 0;

    srand((unsigned int)time(NULL));

    // 0 4 8 _
    char divisoriaVertical[] = {' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '\0'};
    char linhaTopo[] = {'y', ' ', '|', ' ', 'y', ' ', '|', ' ', 'y', '\0'};
    char divisoria[] = {'_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '\0'};
    char linhaTopoRef[] = {'y', ' ', '|', ' ', 'y', ' ', '|', ' ', 'y', '\0'};
    char linhaMeio[] = {'y', ' ', '|', ' ', 'y', ' ', '|', ' ', 'y', '\0'};
    char linhaMeioRef[] = {'y', ' ', '|', ' ', 'y', ' ', '|', ' ', 'y', '\0'};
    char linhaBaixo[] = {'y', ' ', '|', ' ', 'y', ' ', '|', ' ', 'y', '\0'};
    char linhaBaixoRef[] = {'y', ' ', '|', ' ', 'y', ' ', '|', ' ', 'y', '\0'};

    // game
    while (1)
    {

        int tamanho = sizeof(linhaTopo) / sizeof(linhaTopo[0]) - 1;
        int tamanhoMeio = sizeof(linhaMeio) / sizeof(linhaMeio[0]) - 1;
        int tamanhoBaixo = sizeof(linhaBaixo) / sizeof(linhaBaixo[0]) - 1;
        // verificar vitoria
        if (verificarVitoriaJogador(linhaTopo, linhaMeio, linhaBaixo, tamanho))
        {
            printf("%s\n", linhaTopo);
            printf("%s\n", divisoria);
            printf("%s\n", linhaMeio);
            printf("%s\n", divisoria);
            printf("%s\n\n", linhaBaixo);
            printf("\nVoce ganhou.\n");
            jogoFinalizado = 1;
            break;
        }
        else if (verificarVitoriaIa(linhaTopo, linhaMeio, linhaBaixo, tamanho))
        {
            printf("%s\n", linhaTopo);
            printf("%s\n", divisoria);
            printf("%s\n", linhaMeio);
            printf("%s\n", divisoria);
            printf("%s\n\n", linhaBaixo);
            printf("\nVoce perdeu.\n");
            jogoFinalizado = 1;
            break;
        }

        // verificacao empate
        if (todasPosicoesDiferentesTopo(linhaTopo, linhaTopoRef, tamanho) && todasPosicoesDiferentesMeio(linhaMeio, linhaMeioRef, tamanhoMeio) && todasPosicoesDiferentesBaixo(linhaBaixo, linhaBaixoRef, tamanhoBaixo))
        {
            printf("O jogo empatou.\n");
            jogoFinalizado = 1;
            break;
        }

        // turno do jogador
        while (1)
        {
            printf("%s\n", divisoriaVertical);
            printf("%s\n", linhaTopo);
            printf("%s\n", divisoria);
            printf("%s\n", linhaMeio);
            printf("%s\n", divisoria);
            printf("%s\n", linhaBaixo);
            printf("%s\n", divisoriaVertical);
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

                // printf("nao daaaaa");
                break;
            case 2:
                if (linhaMeio[opcaoPosicao] == linhaMeioRef[opcaoPosicao])
                {
                    linhaMeio[opcaoPosicao] = 'x';
                    break;
                }
                // printf("nao daaaaa");
                break;

                linhaMeio[opcaoPosicao] = 'x';
                break;
            case 3:
                if (linhaBaixo[opcaoPosicao] == linhaBaixoRef[opcaoPosicao])
                {
                    linhaBaixo[opcaoPosicao] = 'x';
                    break;
                }
                // printf("nao daaaaa");
                break;

                linhaBaixo[opcaoPosicao] = 'x';
                break;

            default:
                break;
            }

            // acaba o turno do jogador
            break;
        }
        // turno da IA
        while (1)
        {
            int tamanho = sizeof(linhaTopo) / sizeof(linhaTopo[0]) - 1;
            int tamanhoMeio = sizeof(linhaMeio) / sizeof(linhaMeio[0]) - 1;
            int tamanhoBaixo = sizeof(linhaBaixo) / sizeof(linhaBaixo[0]) - 1; // Subtrai 1 para desconsiderar o '\0'
            if (todasPosicoesDiferentesTopo(linhaTopo, linhaTopoRef, tamanho) && todasPosicoesDiferentesMeio(linhaMeio, linhaMeioRef, tamanhoMeio) && todasPosicoesDiferentesBaixo(linhaBaixo, linhaBaixoRef, tamanhoBaixo))
            {
                printf("O jogo empatou.\n");
                jogoFinalizado = 1;
                break;
            }
            int jogadaRealizada = 0;
            int linhaIa = (rand() % 3) + 1;
            opcaoLinha = linhaIa;

            int posicaoIa = (rand() % 3) + 1;
            opcaoPosicao = posicaoIa;

            if (opcaoPosicao == 1)
            {
                opcaoPosicao = 0;
            }
            else if (opcaoPosicao == 2)
            {
                opcaoPosicao = 4;
            }
            else if (opcaoPosicao == 3)
            {
                opcaoPosicao = 8;
            }

            switch (opcaoLinha)
            {
            case 1:
                if (linhaTopo[opcaoPosicao] == linhaTopoRef[opcaoPosicao])
                {
                    linhaTopo[opcaoPosicao] = 'o';
                    jogadaRealizada = 1;
                    break;
                }
                break;
            case 2:
                if (linhaMeio[opcaoPosicao] == linhaMeioRef[opcaoPosicao])
                {
                    linhaMeio[opcaoPosicao] = 'o';
                    jogadaRealizada = 1;
                    break;
                }
                break;
            case 3:
                if (linhaBaixo[opcaoPosicao] == linhaBaixoRef[opcaoPosicao])
                {
                    linhaBaixo[opcaoPosicao] = 'o';
                    jogadaRealizada = 1;
                    break;
                }
                break;
            default:
                printf("Incorreto.");
                break;
            }

            if (jogadaRealizada == 1)
            {
                break;
            }
        }
        if (jogoFinalizado == 1)
        {
            break;
        }
    }
    printf("Pressione alguma tecla para continuar");
    _getch();
    return 0;
}