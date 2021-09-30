#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
double maiorSalario(double salario[])
{
    int i;
    double maior;
    for (i = 1; i <= 100; i++)
        if (salario[i - 1] > salario[i])
            maior = salario[i - 1];
    return maior;
}
double menorSalario(double salario[])
{
    int i;
    double menor;
    for (i = 1; i <= 100; i++)
        if (salario[i - 1] < salario[i])
            menor = salario[i - 1];
    return menor;
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int matricula[100], i, j;
    double salario[100], maior, menor;
    for (i = 0; i < 100; i++)
    {
        printf("Insira a %dª matrícula: ", (i + 1));
        scanf("%d", &matricula[i]);
        if (i > 0)
            for (j = 1; j <= i; j++)
                if (matricula[j - 1] == matricula[i])
                    do
                    {
                        printf("A %dª matrícula não pode ser igual à %dª.\n", (i + 1), j);
                        printf("Insira um novo valor para a %dª matrícula: ", (i + 1));
                        scanf("%d", &matricula[i]);
                    } while (matricula[j - 1] == matricula[i]);
        printf("Insira o %dº salário: ", (i + 1));
        scanf("%lf", &salario[i]);
    }
    maior = maiorSalario(salario);
    menor = menorSalario(salario);
    system("clear");
    for (i = 0; i < 100; i++)
    {
        printf("%dª Matrícula: %d |", (i + 1), matricula[i]);
        printf("%dº Salário: R$ %.2lf\n", (i + 1), salario[i]);
    }
    printf("Maior salário: R$ %.2lf\nMenor salário: R$ %.2lf\n", maior, menor);
    return 0;
}