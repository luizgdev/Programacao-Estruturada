#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QTD_ALUNOS 20
#define QTD_NOTAS_POR_ALUNOS 2
double mediaPadrao(int i, double notas[][QTD_NOTAS_POR_ALUNOS])
{
    double media = 0;
    for (int j = 0; j < QTD_NOTAS_POR_ALUNOS; j++)
        media += notas[i][j];
    media /= QTD_NOTAS_POR_ALUNOS;
    return media;
}
double mediaPonderada4x6(int i, double notas[][QTD_NOTAS_POR_ALUNOS])
{
    double media = 0;
    for (int j = 0; j < QTD_NOTAS_POR_ALUNOS; j++)
        ((j == 0)
             ? (media += (notas[i][j] * 4))
             : (media += (notas[i][j] * 6)));
    media /= 10;
    return media;
}
double mediaPonderada3x7(int i, double notas[][QTD_NOTAS_POR_ALUNOS])
{
    double media = 0;
    for (int j = 0; j < QTD_NOTAS_POR_ALUNOS; j++)
        ((j == 0)
             ? (media += (notas[i][j] * 3))
             : (media += (notas[i][j] * 7)));
    media /= 10;
    return media;
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i, j;
    double notas[QTD_ALUNOS][QTD_NOTAS_POR_ALUNOS];
    double media_aritmetica[QTD_ALUNOS], media_ponderada4x6[QTD_ALUNOS], media_ponderada3x7[QTD_ALUNOS];
    for (i = 0; i < QTD_ALUNOS; i++)
    {
        for (j = 0; j < QTD_NOTAS_POR_ALUNOS; j++)
        {
            ((j == 0)
                 ? (printf("Insira a primeira nota do %dº aluno: ", (i + 1)))
                 : (printf("Insira a segunda nota do %dº aluno: ", (i + 1))));
            scanf("%lf", &notas[i][j]);
        }
        media_aritmetica[i] = mediaPadrao(i, notas);
        media_ponderada4x6[i] = mediaPonderada4x6(i, notas);
        media_ponderada3x7[i] = mediaPonderada3x7(i, notas);
    }
    system("cls");
    printf("\n|                        Médias                         |\n");
    printf("| Alunos  | Aritmética | Ponderada(4x6) | Ponderada(3x7)|\n");
    for (i = 0; i < QTD_ALUNOS; i++)
    {
        if (i < 9)
            ((media_aritmetica[i] == 10)
                 ? (printf("|%dº Aluno |    %.1lf    |      %.1lf      |      %.1lf     |\n", (i + 1), media_aritmetica[i], media_ponderada4x6[i], media_ponderada3x7[i]))
                 : (printf("|%dº Aluno |    %.2lf    |      %.2lf      |      %.2lf     |\n", (i + 1), media_aritmetica[i], media_ponderada4x6[i], media_ponderada3x7[i])));
        else
            ((media_aritmetica[i] == 10)
                 ? (printf("|%dº Aluno|    %.1lf    |      %.1lf      |      %.1lf     |\n", (i + 1), media_aritmetica[i], media_ponderada4x6[i], media_ponderada3x7[i]))
                 : (printf("|%dº Aluno|    %.2lf    |      %.2lf      |      %.2lf     |\n", (i + 1), media_aritmetica[i], media_ponderada4x6[i], media_ponderada3x7[i])));
    }
    return 0;
}