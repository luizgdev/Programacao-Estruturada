#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void leituraTexto(char *texto);
void editaTexto(char *texto);
void mostraTexto(char *texto);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char texto[MAX];
    leituraTexto(texto);
    editaTexto(texto);
    mostraTexto(texto);
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
void mostraTexto(char *texto)
{
    system("clear");
    printf("%s", texto);
}