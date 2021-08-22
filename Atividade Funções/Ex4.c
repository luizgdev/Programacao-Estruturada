#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
int calculaIdade(int ano_nascimento, int ano_atual)
{
    int idade = (ano_atual - ano_nascimento);
    return idade;
}
void obtemNivel(int idade)
{
    if (idade <= 10)
        printf("Idade: %d anos.\nClassificação: Criança.\n", idade);
    else if (idade > 10 && idade < 18)
        printf("Idade: %d anos.\nClassificação: Adolescente.\n", idade);
    else if (idade >= 18 && idade < 25)
        printf("Idade: %d anos.\nClassificação: Jovem.\n", idade);
    else if (idade >= 25 && idade <= 58)
        printf("Idade: %d anos.\nClassificação: Adulto.\n", idade);
    else if (idade > 58)
        printf("Idade: %d anos.\nClassificação: Idoso.\n", idade);
}
void apresentaClassificacao(int idade)
{
    system("clear");
    printf("\nSiga a tabela abaixo para determinar sua classificação de acordo com a idade:\n");
    printf("\n| IDADE <= 10       | CRIANÇA     |\n");
    printf("| 10 > IDADE < 18   | ADOLESCENTE |\n");
    printf("| 18 >= IDADE < 25  | JOVEM       |\n");
    printf("| 25 >= IDADE <= 58 | ADULTO      |\n");
    printf("| IDADE > 58        | IDOSO       |\n\n");
    obtemNivel(idade);
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int ano_nascimento, ano_atual, idade;
    char escolha;
    do
    {
        printf("Insira o ano de nascimento: ");
        scanf("%d", &ano_nascimento);
        printf("Insira o ano atual: ");
        scanf("%d", &ano_atual);
        idade = calculaIdade(ano_nascimento, ano_atual);
        apresentaClassificacao(idade);
        printf("\nDeseja continuar? (S/N)\n");
        scanf(" %c", &escolha);
        escolha = toupper(escolha);
    } while (escolha == 'S');
    return 0;
}