#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 3
#define MAX_C 50

typedef struct Dados
{
    char nome[MAX][MAX_C];
    char endereco[MAX][MAX_C];
    int telefone[MAX];
} DADOS;

void leituraDados(DADOS *ptr);
void mostraDados(DADOS pessoa);
void limpaJanela();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    DADOS pessoa;
    leituraDados(&pessoa);
    mostraDados(pessoa);
    return 0;
}
void leituraDados(DADOS *ptr)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("Informe o %dº nome: ", (i + 1));
        fgets((*ptr).nome[i], MAX_C, stdin);
        printf("Informe o %dº endereço: ", (i + 1));
        fgets((*ptr).endereco[i], MAX_C, stdin);
        printf("Informe o %dº telefone: ", (i + 1));
        scanf("%d", &(*ptr).telefone[i]);
        getchar();
    }
}
void mostraDados(DADOS pessoa)
{
    limpaJanela();
    puts("Dados cadastrados\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("Nome: %s", pessoa.nome[i]);
        printf("Endereço: %s", pessoa.endereco[i]);
        printf("Telefone: %d", pessoa.telefone[i]);
        puts("\n");
    }
}
void limpaJanela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}