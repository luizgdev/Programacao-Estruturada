#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int matricula[50], mes[50], i, j, menor = 0, cont = 0;
    for (i = 0; i < 50; i++)
    {
        printf("Insira a matrícula do %dº empregado: ", (i + 1));
        scanf("%d", &matricula[i]);
        if (matricula[i] == 0)
            break;
        else
        {
            cont++;
            printf("Insira a quantidade de meses que o %dº empregado trabalhou: ", (i + 1));
            scanf("%d", &mes[i]);
            for (j = 0; j < i; j++)
            {
                if (mes[j] == mes[i])
                    do
                    {
                        printf("Não pode existir empregados com a mesma quantidade de meses trabalhados.\n");
                        printf("Insira a quantidade de meses que o %dº empregado trabalhou: ", (i + 1));
                        scanf("%d", &mes[i]);
                    } while (mes[j] == mes[i]);
            }
        }
    }

    return 0;
}