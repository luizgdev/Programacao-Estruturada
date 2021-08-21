#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i, dados[80], numero, quantidade = 0, posicao[80], aux = 0;
    printf("Insira um vetor de até 80 números: ");
    for (i = 0; i < 80; i++)
        scanf("%d", &dados[i]);
    printf("Insira o número de verificação do vetor: ");
    scanf("%d", &numero);
    for (i = 0; i < 80; i++)
        if (dados[i] == numero)
        {
            quantidade++;
            posicao[aux] = i;
            aux++;
        }
    printf("A quantidade de vezes que o número aparece no vetor é: %d\n", quantidade);
    printf("As posições em que o número aparece no vetor são: ");
    for (i = 0; i < quantidade; i++)
        printf("%d ", posicao[i]);
    printf("\n");
    return 0;
}