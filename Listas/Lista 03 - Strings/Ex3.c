#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define PESSOAS 5
#define MAX 50

void leituraNomes(char primeiro_nome[PESSOAS][MAX], char ultimo_nome[PESSOAS][MAX]);
void apresentaTamanho(char primeiro_nome[PESSOAS][MAX], char ultimo_nome[PESSOAS][MAX], int i);
void concatenaNomes(char primeiro_nome[PESSOAS][MAX], char ultimo_nome[PESSOAS][MAX], char nome_completo[PESSOAS][MAX * 2]);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char primeiro_nome[PESSOAS][MAX];
    char ultimo_nome[PESSOAS][MAX];
    char nome_completo[PESSOAS][MAX * 2];
    leituraNomes(primeiro_nome, ultimo_nome);
    concatenaNomes(primeiro_nome, ultimo_nome, nome_completo);
    return 0;
}
void leituraNomes(char primeiro_nome[PESSOAS][MAX], char ultimo_nome[PESSOAS][MAX])
{
    for (int i = 0; i < PESSOAS; i++)
    {
        printf("Informe o %dº primeiro nome: ", (i + 1));
        fflush(stdin);
        scanf("%s", primeiro_nome[i]);
        printf("Informe o %dº último nome: ", (i + 1));
        fflush(stdin);
        scanf("%s", ultimo_nome[i]);
        apresentaTamanho(primeiro_nome, ultimo_nome, i);
    }
}
void apresentaTamanho(char primeiro_nome[PESSOAS][MAX], char ultimo_nome[PESSOAS][MAX], int i)
{
    printf("\nO primeiro nome tem %d letras.\n", (int)strlen(primeiro_nome[i]));
    printf("O último nome tem %d letras.\n\n", (int)strlen(ultimo_nome[i]));
}
void concatenaNomes(char primeiro_nome[PESSOAS][MAX], char ultimo_nome[PESSOAS][MAX], char nome_completo[PESSOAS][MAX * 2])
{
    for (int i = 0; i < PESSOAS; i++)
    {
        strcat(primeiro_nome[i], " ");
        strcpy(nome_completo[i], strcat(primeiro_nome[i], ultimo_nome[i]));
        printf("%dº nome completo: %s\n", (i + 1), nome_completo[i]);
    }
}