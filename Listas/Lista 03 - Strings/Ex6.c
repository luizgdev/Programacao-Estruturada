#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX 30 + 2

void leituraNome(char *nome);
void formataNome(char *nome);
void apresentaNome(char *nome);
bool paraPrograma();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nome[MAX];
    do
    {
        leituraNome(nome);
        formataNome(nome);
        apresentaNome(nome);
    } while (paraPrograma() == true);
    return 0;
}
void leituraNome(char *nome)
{
    printf("Informe um nome com até 30 caracteres: ");
    fgets(nome, MAX, stdin);
}
void formataNome(char *nome)
{
    for (int i = 0; nome[i] != '\0'; i++)
        nome[i] = toupper(nome[i]);
}
void apresentaNome(char *nome)
{
    system("clear");
    for (int i = 0; i < 60; i++)
        printf(" ");
    printf("%s", nome);
    for (int i = 0; i < 24; i++)
    {
        printf("\n");
        if (i == 20)
            printf("O nome tem %d caracteres.", (int)strlen(nome) - 1);
        else if (i == 23)
            printf("Deseja continuar? [S/N]: ");
    }
}
bool paraPrograma()
{
    char aux;
    aux = getchar();
    if (aux == 's' || aux == 'S')
    {
        getchar();
        return true;
    }
    else
    {
        getchar();
        return false;
    }
}