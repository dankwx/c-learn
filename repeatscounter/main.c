#include <stdio.h>

// iteracao para printar valores da array
void printarArray(char *arr[], int tamanho)
{
    int i = 0;

    while (i < tamanho)
    {
        printf("%s\n", arr[i]);
        i++;
    }
    return;
}

// adicionar elemento na array que começa vazia
void adicionarElementos(char *arrUm[], char *arrDois[], char *arrVazia[], int tamanho)
{
    int i = 0;
    int posicaoArrVazia = 0;
    while (i < tamanho)
    {
        if (arrUm[i] == arrDois[i])
        {
            arrVazia[posicaoArrVazia] = arrUm[i];
            posicaoArrVazia++;
            i++;
        }
        else
        {
            i++;
        }
    }

    return;
}
int main()

{
    char *arrayNomes[] = {"daniel", "clarissa", "julia"};
    char *arrayNames[] = {"daniel", "clarissa", "julia"};
    char *arrayInicioVazia[3] = {};
    int tamanhoArrayPopulada = sizeof(arrayNomes) / sizeof(arrayNomes[0]);
    int tamanhoArr = sizeof(arrayInicioVazia) / sizeof(arrayInicioVazia[0]);

    adicionarElementos(arrayNomes, arrayNames, arrayInicioVazia, tamanhoArrayPopulada);
    printarArray(arrayInicioVazia, tamanhoArr);

    return 0;
}