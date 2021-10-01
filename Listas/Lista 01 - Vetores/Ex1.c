#include <stdio.h>
#include <locale.h>

#define MAX 30

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double notas[MAX];
    for (int i = 0; i < MAX; i++)
    {
        printf("Digite a nota do %dº aluno: ", (i + 1));
        scanf("%lf", &notas[i]);
    }
    for (int i = 0; i < MAX; i++)
        printf("%dª nota: %.2lf\n", (i + 1), notas[i]);
    return 0;
}
