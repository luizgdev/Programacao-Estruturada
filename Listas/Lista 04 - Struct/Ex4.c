#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10
#define MAX_C 50

typedef struct
{
    char marca[MAX_C];
    char modelo[MAX_C];
    char cor[MAX_C];
    int quantidade_portas;
    char motorizacao[MAX_C];
} VEICULO;

void leituraDadosVeiculo(VEICULO *dados);
void mostraDadosVeiculo(VEICULO *dados);
void limpaJanela();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    VEICULO dados[MAX];
    int menu;
    do
    {
        limpaJanela();
        printf("Bem-vindo, informe o que deseja fazer de acordo com a tabela abaixo:\n");
        printf("1 - Cadastrar veículos\n");
        printf("2 - Mostrar lista de veículos\n");
        scanf("%d", &menu);
        getchar();
        switch (menu)
        {
        case 1:
            leituraDadosVeiculo(dados);
            break;
        case 2:
            mostraDadosVeiculo(dados);
            break;
        default:
            puts("Opção inválida.");
            break;
        }
    } while (menu != 2);
    return 0;
}
void leituraDadosVeiculo(VEICULO *dados)
{
    for (int i = 0; i < MAX; i++)
    {
        limpaJanela();
        printf("Para completar o cadastro siga as instruções abaixo:\n");
        printf("Veículo número %d:\n", i + 1);
        printf("Informe a marca do veículo: ");
        fgets(dados[i].marca, MAX_C, stdin);
        printf("Informe o modelo do veículo: ");
        fgets(dados[i].modelo, MAX_C, stdin);
        printf("Informe a cor do veículo: ");
        fgets(dados[i].cor, MAX_C, stdin);
        printf("Informe a quantidade de portas do veículo: ");
        scanf("%d", &dados[i].quantidade_portas);
        getchar();
        printf("Informe qual é o motor do veículo: ");
        fgets(dados[i].motorizacao, MAX_C, stdin);
    }
}
void mostraDadosVeiculo(VEICULO *dados)
{
    limpaJanela();
    for (int i = 0; i < MAX; i++)
    {
        printf("Veículo número %d:\n", i + 1);
        printf("Marca: %s", dados[i].marca);
        printf("Modelo: %s", dados[i].modelo);
        printf("Cor: %s", dados[i].cor);
        printf("Quantidade de portas: %d\n", dados[i].quantidade_portas);
        printf("Motorização: %s", dados[i].motorizacao);
        printf("\n");
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