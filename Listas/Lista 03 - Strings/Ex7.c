#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define MAX 50 + 2

void leituraFrase(char *frase);
void leituraNome(char *nome);
void editaNome(char *nome);
void concatenaNomeFrase(char *nome, char *frase, char *mensagem);
void mostraMensagem(char *mensagem);
void limpaJanela();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char frase[MAX];
    char nome[MAX];
    char mensagem[MAX * 2];
    leituraFrase(frase);
    leituraNome(nome);
    editaNome(nome);
    concatenaNomeFrase(nome, frase, mensagem);
    mostraMensagem(mensagem);
    return 0;
}
void leituraFrase(char *frase)
{
    printf("Digite a frase a ser transmitida aos candidatos da próxima eleição: ");
    fgets(frase, MAX, stdin);
}
void leituraNome(char *nome)
{
    printf("Informe o nome do candidato desejado: ");
    fgets(nome, MAX, stdin);
}
void editaNome(char *nome)
{
    int i = 0;
    for (i = 0; nome[i] != '\n'; i++)
        nome[i] = toupper(nome[i]);
    nome[i] = '\0';
}
void concatenaNomeFrase(char *nome, char *frase, char *mensagem)
{
    strcpy(mensagem, strcat(nome, ": "));
    strcat(mensagem, frase);
}
void mostraMensagem(char *mensagem)
{
    limpaJanela();
    for (int i = 0; i < 4; i++)
        printf("\n");
    printf("%s", mensagem);
    sleep(10);
}
void limpaJanela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}