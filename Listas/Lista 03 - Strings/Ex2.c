/*
Desenvolva  um  programa  que  solicite  o  nome  de  cinco  equipamentos  de  informática.
Compare  os  cinco nomes  fornecidos  para  verificar  se  existe  algum  solicitado  em 
duplicidade  e  informe  o  usuário  somente  o nome duplicado.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define MAX 5
#define MAX_C 50

void leituraNomes(char nome_equipamentos[MAX][MAX_C]);
void verificaNomes(char nome_equipamentos[MAX][MAX_C]);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char nome_equipamentos[MAX][MAX_C];
    leituraNomes(nome_equipamentos);
    verificaNomes(nome_equipamentos);
    return 0;
}
void leituraNomes(char nome_equipamentos[MAX][MAX_C])
{
    for (int i = 0; i < MAX; i++)
    {
        printf("Informe o nome do %dº equipamento: ", (i + 1));
        fgets(nome_equipamentos[i], MAX_C, stdin);
    }
}
void verificaNomes(char nome_equipamentos[MAX][MAX_C])
{
    char aux[MAX_C];
    bool tmp = false;
    for (int i = 0; i < MAX; i++)
    {
        strcpy(aux, nome_equipamentos[i]);
        for (int j = 0; j < MAX; j++)
            if (j != i && strcmp(aux, nome_equipamentos[j]) == 0)
            {
                tmp = true;
                printf("Foi encontrado um equipamento com nome repetido: %s\n", aux);
            }
    }
    if (tmp == false)
        puts("Não há itens repetidos.");
}