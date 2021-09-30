#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 5
double calculaMedia(double *alturas)
{
    double func_soma = 0, func_media = 0;
    for (int i = 0; i < MAX; i++)
        func_soma += alturas[i];
    func_media = (func_soma / MAX);
    return func_media;
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    double alturas[MAX], media;
    for (int i = 0; i < MAX; i++)
    {
        printf("Digite a %dª altura: ", (i + 1));
        scanf("%lf", &alturas[i]);
    }
    media = calculaMedia(alturas);
    system("cls");
    printf("A média aritmética das %d alturas é: %.2lf metros.\n", MAX, media);
    return 0;
}