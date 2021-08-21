#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int idade[100], i, j, maior;
    double media = 0;
    for (i = 0; i < 100; i++)
    {
        printf("Digite a %dª idade: ", (i + 1));
        scanf("%d", &idade[i]);
        media += (double)idade[i];
        if (i > 0)
            for (j = 1; j <= i; j++)
                if (idade[j] > idade[j - 1])
                    maior = idade[j];
    }
    media /= 100;
    printf("Media de idade: %.1lf anos.\nMaior idade: %d anos.\n", media, maior);
    printf("Posição da maior idade no vetor: ");
    for (i = 0; i < 100; i++)
        if (idade[i] == maior)
            printf("%d ", i);
    printf("\n");
    return 0;
}