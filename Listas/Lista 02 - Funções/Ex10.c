#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define quantidade_notas 2
double mediaPonderada(int i, double notas_alunos[][quantidade_notas])
{
    int j;
    double media = 0;
    for (j = 0; j < quantidade_notas; j++)
        ((j == 0)
             ? (media += (notas_alunos[i][j] * 3))
             : (media += (notas_alunos[i][j] * 7)));
    media /= 10;
    return media;
}
void verificaExibeResultado(char *nome_disciplina, int quantidade_alunos, double *medias_notas, char nomes_alunos[quantidade_alunos][100], double notas_alunos[quantidade_alunos][quantidade_notas])
{
    int i;
    system("cls");
    printf("Disciplina: %s.\n\n", nome_disciplina);
    for (i = 0; i < quantidade_alunos; i++)
    {
        printf("Aluno(a): %s.\n", nomes_alunos[i]);
        printf("Nota Teórica: %.2lf | ", notas_alunos[i][0]);
        printf("Nota Prática: %.2lf | ", notas_alunos[i][1]);
        printf("Média: %.2lf\n", medias_notas[i]);
        ((medias_notas[i] >= 5)
             ? (printf("Situação: Aprovado.\n\n"))
             : (printf("Situação: Reprovado.\n\n")));
    }
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nome_disciplina[100];
    int i, j, quantidade_alunos;
    printf("Insira o nome da disciplina: ");
    scanf("%[^\n]", nome_disciplina);
    printf("Insira a quantidade de alunos: ");
    scanf("%d", &quantidade_alunos);
    double notas_alunos[quantidade_alunos][quantidade_notas], medias_notas[quantidade_alunos];
    char nomes_alunos[quantidade_alunos][100];
    for (i = 0; i < quantidade_alunos; i++)
    {
        getchar();
        printf("Insira o nome do %dº aluno: ", (i + 1));
        scanf("%[^\n]", nomes_alunos[i]);
        for (j = 0; j < quantidade_notas; j++)
        {
            printf("Insira a %dª nota do %dº aluno: ", (j + 1), (i + 1));
            scanf("%lf", &notas_alunos[i][j]);
        }
        medias_notas[i] = mediaPonderada(i, notas_alunos);
    }
    verificaExibeResultado(nome_disciplina, quantidade_alunos, medias_notas, nomes_alunos, notas_alunos);
    return 0;
}