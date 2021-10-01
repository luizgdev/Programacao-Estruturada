#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int quantidade_de_alunos;
    printf("Informe a quantidade de alunos da turma: ");
    scanf("%d", &quantidade_de_alunos);
    double notas[quantidade_de_alunos];
    for (int i = 0; i < quantidade_de_alunos; i++)
    {
        printf("Digite a nota do %dº aluno: ", (i + 1));
        scanf("%lf", &notas[i]);
    }
    for (int i = 0; i < quantidade_de_alunos; i++)
        printf("%dª nota: %.2lf\n", (i + 1), notas[i]);
    return 0;
}