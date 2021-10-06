#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 50

struct DadosAluno
{
    char nome[MAX];
    int idade;
};

void leituraDadosAluno(struct DadosAluno *ptr);
void mostraDadosAluno(struct DadosAluno aluno);
void limpaJanela();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct DadosAluno aluno;
    leituraDadosAluno(&aluno);
    mostraDadosAluno(aluno);
    return 0;
}
void leituraDadosAluno(struct DadosAluno *ptr)
{
    printf("Informe o nome do aluno: ");
    fgets((*ptr).nome, MAX, stdin);
    printf("Informe a idade do aluno: ");
    scanf("%d", &(*ptr).idade);
    getchar();
}
void mostraDadosAluno(struct DadosAluno aluno)
{
    limpaJanela();
    printf("Nome: %s", aluno.nome);
    printf("Idade: %d\n", aluno.idade);
}
void limpaJanela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}