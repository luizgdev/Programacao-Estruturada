#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 3
void lerOrganizaImprimePesos(double *pesos)
{
    int i, j;
    double aux;
    for (i = 0; i < MAX; i++)
    {
        printf("Digite o %dº peso: ", (i + 1));
        scanf("%lf", &pesos[i]);
    }
    for (i = 0; i < (MAX - 1); i++)
    {
        for (j = (i + 1); j < MAX; j++)
        {
            if (pesos[i] > pesos[j])
            {
                aux = pesos[i];
                pesos[i] = pesos[j];
                pesos[j] = aux;
            }
        }
    }
    system("cls");
    printf("Pesos Organizados: ");
    for (i = 0; i < MAX; i++)
        ((i < (MAX - 1)) ? (printf("%.2lf Kg, ", pesos[i])) : (printf("%.2lf Kg.\n", pesos[i])));
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    double pesos[MAX];
    lerOrganizaImprimePesos(pesos);
    return 0;
}