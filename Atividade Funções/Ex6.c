#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void apresentaPorcentagem(int quantidade_de_alunos, int alunos_aprovados, int alunos_reprovados)
{
    double porcentagem_aprovados = (((double)alunos_aprovados / 100) * (double)quantidade_de_alunos);
    double porcentagem_reprovados = (((double)alunos_reprovados / 100) * (double)quantidade_de_alunos);
    system("clear");
    printf("De %d alunos:\n", quantidade_de_alunos);
    printf("%.2lf%% dos alunos foram aprovados.\n", porcentagem_aprovados);
    printf("%.2lf%% dos alunos foram reprovados.\n", porcentagem_reprovados);
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int quantidade_de_alunos, alunos_aprovados, alunos_reprovados;
    printf("Digite a quantidade de alunos matriculados: ");
    scanf("%d", &quantidade_de_alunos);
    printf("Digite a quantidade de alunos aprovados: ");
    scanf("%d", &alunos_aprovados);
    printf("Digite a quantidade de alunos reprovados: ");
    scanf("%d", &alunos_reprovados);
    apresentaPorcentagem(quantidade_de_alunos, alunos_aprovados, alunos_reprovados);
    return 0;
}