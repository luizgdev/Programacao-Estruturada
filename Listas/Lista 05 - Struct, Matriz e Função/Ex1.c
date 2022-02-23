#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define L 2
#define C 2

typedef struct
{
    int codigo;
    char nome[50 + 1];
    double preco;
    int baixa;
} PRODUTO[L][C];

void leitura(PRODUTO *ptr)
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            puts("codigo:");
            scanf("%d", &ptr[i][j]->codigo);
            puts("nome:");
            getchar();
            fgets(ptr[i][j]->nome, 50 + 1, stdin);
            puts("preço:");
            scanf("%lf", &ptr[i][j]->preco);
            puts("baixa:");
            scanf("%d", &ptr[i][j]->baixa);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    PRODUTO dados;

    leitura(&dados);

    return 0;
}