#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define PESSOAS 2
#define MAX 50

void leituraNomes(char nome[PESSOAS][MAX], char sobrenome[PESSOAS][MAX]);
void apresentaNomes(char nome[PESSOAS][MAX], char sobrenome[PESSOAS][MAX]);
bool escolha();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nome[PESSOAS][MAX];
    char sobrenome[PESSOAS][MAX];
    do
    {
        system("clear");
        leituraNomes(nome, sobrenome);
        apresentaNomes(nome, sobrenome);
    } while (escolha() == true);

    return 0;
}
void leituraNomes(char nome[PESSOAS][MAX], char sobrenome[PESSOAS][MAX])
{
    for (int i = 0; i < PESSOAS; i++)
    {
        printf("Informe o %dº nome e sobrenome: ", (i + 1));
        fgets(nome[i], MAX, stdin);
        printf("Informe o %dº sobrenome: ", (i + 1));
        fgets(sobrenome[i], MAX, stdin);
    }
}
void apresentaNomes(char nome[PESSOAS][MAX], char sobrenome[PESSOAS][MAX])
{
    system("clear");
    for (int i = 0; i < PESSOAS; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            nome[i][j] = toupper(nome[i][j]);
            sobrenome[i][j] = tolower(sobrenome[i][j]);
        }
        printf("%dº Nome e sobrenome: %s", (i + 1), nome[i]);
        printf("\t%s\n", sobrenome[i]);
    }
}
bool escolha()
{
    char aux[4 + 2];
    printf("Deseja continuar? [Sim/Não]: ");
    fgets(aux, 4 + 2, stdin);
    for (int i = 0; i < 4 + 2; i++)
        aux[i] = tolower(aux[i]);
    if (strcmp(aux, "sim\n") == 0)
        return true;
    else if (strcmp(aux, "não\n") == 0 || strcmp(aux, "nÃo\n") == 0)
        return false;
    else
    {
        if (strchr(aux, '\n') == NULL)
            while (getchar() != '\n')
                ;
        puts("Informe apenas \"Sim\" ou \"Não\".");
        escolha();
    }
}
