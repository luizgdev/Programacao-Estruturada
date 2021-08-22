#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#define QTD 100
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i;
    double preco[QTD], aumento = 10;
    char escolha;
    for (i = 0; i < QTD; i++)
    {
        printf("Insira o preço do %dº CD: ", (i + 1));
        scanf("%lf", &preco[i]);
    }
    printf("Deseja efetuar o aumento automático de 10%%? (S/N)\n");
    scanf(" %c", &escolha);
    escolha = toupper(escolha);
    if (escolha == 'S')
    {
        for (i = 0; i < QTD; i++)
        {
            printf("Preço antigo: R$ %.2lf | ", preco[i]);
            preco[i] += (preco[i] * (aumento / 100.0));
            printf("Preço novo: R$ %.2lf\n", preco[i]);
        }
        printf("Aumento efetuado com sucesso.\n");
    }
    else if (escolha == 'N')
    {
        printf("Digite o percentual de aumento a ser efetuado: ");
        scanf("%lf", &aumento);
        for (i = 0; i < QTD; i++)
        {
            printf("Preço antigo: R$ %.2lf | ", preco[i]);
            preco[i] += (preco[i] * (aumento / 100.0));
            printf("Preço novo: R$ %.2lf\n", preco[i]);
        }
        printf("Aumento efetuado com sucesso.\n");
    }
    return 0;
}