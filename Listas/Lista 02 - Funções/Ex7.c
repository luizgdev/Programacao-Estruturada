#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void lerEquacao(int numeros[2][3], char operadores[2][2])
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        printf("Digite a %dª equação:\n", (i + 1));
        for (j = 0; j < 3; j++)
        {
            printf("%dº numero: ", (j + 1));
            scanf("%d", &numeros[i][j]);
            if (j < 2)
            {
                printf("%dº operador: ", (j + 1));
                scanf(" %c", &operadores[i][j]);
            }
        }
    }
}
void calculaEquacao(int numeros[2][3], char operadores[2][2], int *resultadoEquacao)
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        if ((operadores[i][0] == '*' || operadores[i][0] == '/') && (operadores[i][1] == '*' || operadores[i][1] == '/'))
        {
            if (operadores[i][0] == '*')
            {
                ((operadores[i][1] == '*')
                     ? (resultadoEquacao[i] = ((numeros[i][0] * numeros[i][1]) * numeros[i][2]))
                     : (resultadoEquacao[i] = ((numeros[i][0] * numeros[i][1]) / numeros[i][2])));
            }
            else if (operadores[i][0] == '/')
            {
                ((operadores[i][1] == '/')
                     ? (resultadoEquacao[i] = ((numeros[i][0] / numeros[i][1]) / numeros[i][2]))
                     : (resultadoEquacao[i] = ((numeros[i][0] / numeros[i][1]) * numeros[i][2])));
            }
        }
        else if ((operadores[i][0] == '+' || operadores[i][0] == '-') && (operadores[i][1] == '*' || operadores[i][1] == '/'))
        {
            if (operadores[i][0] == '+')
            {
                ((operadores[i][1] == '*')
                     ? (resultadoEquacao[i] = (numeros[i][0] + (numeros[i][1] * numeros[i][2])))
                     : (resultadoEquacao[i] = (numeros[i][0] + (numeros[i][1] / numeros[i][2]))));
            }
            else if (operadores[i][0] == '-')
            {
                ((operadores[i][1] == '/')
                     ? (resultadoEquacao[i] = (numeros[i][0] - (numeros[i][1] / numeros[i][2])))
                     : (resultadoEquacao[i] = (numeros[i][0] - (numeros[i][1] * numeros[i][2]))));
            }
        }
        else if ((operadores[i][0] == '*' || operadores[i][0] == '/') && (operadores[i][1] == '+' || operadores[i][1] == '-'))
        {
            if (operadores[i][0] == '*')
            {
                ((operadores[i][1] == '+')
                     ? (resultadoEquacao[i] = ((numeros[i][0] * numeros[i][1]) + numeros[i][2]))
                     : (resultadoEquacao[i] = ((numeros[i][0] * numeros[i][1]) - numeros[i][2])));
            }
            else if (operadores[i][0] == '/')
            {
                ((operadores[i][1] == '-')
                     ? (resultadoEquacao[i] = ((numeros[i][0] / numeros[i][1]) - numeros[i][2]))
                     : (resultadoEquacao[i] = ((numeros[i][0] / numeros[i][1]) + numeros[i][2])));
            }
        }
        else if ((operadores[i][0] == '+' || operadores[i][0] == '-') && (operadores[i][1] == '+' || operadores[i][1] == '-'))
        {
            if (operadores[i][0] == '+')
            {
                ((operadores[i][1] == '+')
                     ? (resultadoEquacao[i] = ((numeros[i][0] + numeros[i][1]) + numeros[i][2]))
                     : (resultadoEquacao[i] = ((numeros[i][0] + numeros[i][1]) - numeros[i][2])));
            }
            else if (operadores[i][0] == '-')
            {
                ((operadores[i][1] == '-')
                     ? (resultadoEquacao[i] = ((numeros[i][0] - numeros[i][1]) - numeros[i][2]))
                     : (resultadoEquacao[i] = ((numeros[i][0] - numeros[i][1]) + numeros[i][2])));
            }
        }
    }
}
void verificaImparPar(int i, int *resultadoEquacao)
{
    ((resultadoEquacao[i] % 2 == 0) ? (printf("(PAR)\n")) : (printf("(ÍMPAR)\n")));
}
void imprimeResultadoEquacao(int numeros[2][3], char operadores[2][2], int *resultadoEquacao)
{
    int i, j;
    system("cls");
    for (i = 0; i < 2; i++)
    {
        printf("%dª Equação: (", (i + 1));
        for (j = 0; j < 3; j++)
        {
            if (j < 2)
            {
                printf("%d ", numeros[i][j]);
                printf("%c ", operadores[i][j]);
            }
            else
                printf("%d", numeros[i][j]);
        }
        printf(") = %d ", resultadoEquacao[i]);
        verificaImparPar(i, resultadoEquacao);
    }
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numeros[2][3], resultadoEquacao[2];
    char operadores[2][2];
    lerEquacao(numeros, operadores);
    calculaEquacao(numeros, operadores, resultadoEquacao);
    imprimeResultadoEquacao(numeros, operadores, resultadoEquacao);
    return 0;
}