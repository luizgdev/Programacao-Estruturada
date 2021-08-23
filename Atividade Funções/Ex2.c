#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
double funcao_exponencial(double x, int n)
{
    double resultado = x;
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else if (n > 1)
    {
        for (int i = 1; i < n; i++)
            resultado *= x;
        return resultado;
    }
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n;
    double x, valor_exponencial;
    printf("Insira o valor da base: ");
    scanf("%lf", &x);
    printf("Insira o valor do expoente: ");
    scanf("%d", &n);
    valor_exponencial = funcao_exponencial(x, n);
    system("cls");
    printf("O resultado de %.2lf elevado a %d é: %.2lf.\n", x, n, valor_exponencial);
    return 0;
}