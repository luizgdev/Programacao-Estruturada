#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

void leituraNome(char *nome_completo);
void editaNome(char *nome_completo, char *nome_formatado);
void mostraNome(char *nome_formatado);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nome_completo[MAX];
    char nome_formatado[MAX];
    leituraNome(nome_completo);
    editaNome(nome_completo, nome_formatado);
    mostraNome(nome_formatado);
    return 0;
}
void leituraNome(char *nome_completo)
{
    printf("Informe o nome completo: ");
    scanf("%[^\n]", nome_completo);
}
void editaNome(char *nome_completo, char *nome_formatado)
{
    int i, j = 0;
    char primeiro_nome[MAX];
    char ultimo_sobrenome[MAX];
    char tmp[MAX];
    for (i = strlen(nome_completo) - 1; !isspace(nome_completo[i]); i--)
    {
        tmp[j] = nome_completo[i];
        j++;
    }
    tmp[j]='\0';
    j = 0;
    for (i = strlen(tmp) - 1; i >= 0; i--)
    {
        ultimo_sobrenome[j] = tmp[i];
        j++;
    }
    strcat(ultimo_sobrenome, "/");
    for (i = 0; !isspace(nome_completo[i]); i++)
        primeiro_nome[i] = nome_completo[i];
    strcpy(nome_formatado, strcat(ultimo_sobrenome, primeiro_nome));
}
void mostraNome(char *nome_formatado)
{
    printf("%s\n", nome_formatado);
}