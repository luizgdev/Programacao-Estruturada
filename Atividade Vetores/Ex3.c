#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int soma = 0, dados[100], i;
    for (i = 0; i < 100; i++)
    {
        printf("Insira o %dº valor a ser somado: ", (i + 1));
        scanf("%d", &dados[i]);
        soma += dados[i];
    }
    printf("Soma = %d\n", soma);
    return 0;
}