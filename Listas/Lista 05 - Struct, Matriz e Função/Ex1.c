#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int codigo;
    char nome[50 + 1];
    double preco;
    int baixa;
} PRODUTO;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    PRODUTO dados[4][6];

    return 0;
}