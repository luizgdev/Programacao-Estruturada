#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int i;
    double notas[30];
    for (i = 0; i < 30; i++)
    {
        printf("Digite a nota do %dº aluno: ", (i + 1));
        scanf("%lf", &notas[i]);
    }
    for (i = 0; i < 30; i++)
        printf("%dª nota = %.2lf\n", (i + 1), notas[i]);
    return 0;
}
