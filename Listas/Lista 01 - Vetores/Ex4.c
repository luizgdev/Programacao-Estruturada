#include <stdio.h>
#include <string.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");
    char letras[30];
    printf("Insira um vetor de até 30 letras: ");
    fflush(stdin);
    scanf("%[^\n]", letras);
    printf("A ordem inversa do vetor é: ");
    for (int i = strlen(letras); i >= 0; i--)
        printf("%c", letras[i]);
    printf("\n");
    return 0;
}