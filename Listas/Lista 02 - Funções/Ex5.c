#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
void classificacaoLocal(char *nome)
{
    long int quantidade_de_habitantes;
    scanf("%ld", &quantidade_de_habitantes);
    system("cls");
    if (quantidade_de_habitantes > 0 && quantidade_de_habitantes <= 5000)
        printf("Nome: %s.\nQuantidade de habitantes: %ld.\nClassificação: VILA.\n", nome, quantidade_de_habitantes);
    else if (quantidade_de_habitantes > 5000 && quantidade_de_habitantes <= 15000)
        printf("Nome: %s.\nQuantidade de habitantes: %ld.\nClassificação: DISTRITO.\n", nome, quantidade_de_habitantes);
    else if (quantidade_de_habitantes > 15000 && quantidade_de_habitantes <= 1000000)
        printf("Nome: %s.\nQuantidade de habitantes: %ld.\nClassificação: CIDADE.\n", nome, quantidade_de_habitantes);
    else if (quantidade_de_habitantes > 1000000)
        printf("Nome: %s.\nQuantidade de habitantes: %ld.\nClassificação: METROPOLE.\n", nome, quantidade_de_habitantes);
}
void nomeLocal()
{
    char nome[50];
    fflush(stdin);
    scanf(" %[^\n]", nome);
    printf("Digite a quantidade de habitantes: ");
    classificacaoLocal(nome);
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    char escolha;
    do
    {
        printf("Digite o nome do local: ");
        nomeLocal();
        printf("\nDeseja continuar? (S/N)\n");
        scanf(" %c", &escolha);
        escolha = toupper(escolha);
    } while (escolha == 'S');
    return 0;
}