#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
double leValidaPeso(double peso)
{
    printf("Insira o peso: ");
    do
    {
        scanf("%lf", &peso);
        if (peso <= 0)
        {
            printf("O peso não pode ser negativo ou nulo.\n");
            printf("Insira um novo peso: ");
        }
    } while (peso <= 0);
    return peso;
}
void apresentaGrama(double peso)
{
    printf("Gramas: %.2lf\n", (peso * 1000));
}
void apresentaTonelada(double peso)
{
    printf("Toneladas: %.3lf\n", (peso / 1000));
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    double peso;
    peso = leValidaPeso(peso);
    system("cls");
    printf("Peso: \n");
    printf("Kilogramas: %.2lf\n", peso);
    apresentaGrama(peso);
    apresentaTonelada(peso);
    return 0;
}