#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void leituraTexto(char *texto);
void editaTexto(char *texto);
int contaPalavras(char *texto, int contador);
void mostraTexto(char *texto, int contador);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char texto[MAX];
    leituraTexto(texto);
    editaTexto(texto);
    int contador = contaPalavras(texto, contador);
    mostraTexto(texto, contador);
    return 0;
}
void leituraTexto(char *texto)
{
    puts("Insira o texto:");
    fgets(texto, MAX, stdin);
}
void editaTexto(char *texto)
{
    for (int i = 0; texto[i] != '\n'; i++)
        texto[i] = tolower(texto[i]);
    texto[0] = toupper(texto[0]);
    for (int i = 0; texto[i] != '\n'; i++)
        if (isspace(texto[i]))
            texto[i + 1] = toupper(texto[i + 1]);
}
int contaPalavras(char *texto, int contador)
{
    contador = 0;
    for (int i = 0; texto[i] != '\n'; i++)
        if (isspace(texto[i]))
            contador++;
    return ++contador;
}
void mostraTexto(char *texto, int contador)
{
    system("clear");
    printf("%s", texto);
    for (int i = 0; i < 40 + strlen("O texto tem %d palavras.\n"); i++)
        printf(" ");
    printf("O texto tem %d palavras.\n", contador);
}