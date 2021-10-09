#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX 5
#define MAX_C 50

typedef struct
{
    char rua[MAX_C];
    char bairro[MAX_C];
    char estado[MAX_C];
    char cidade[MAX_C];
    char cep[11];
} CASA;
typedef struct
{
    char nome[MAX_C];
    char identidade[11];
    char telefone[16];
    CASA endereco;
    char cpf[16];
    int idade;
    double salario;
    char estado_civil[MAX_C];
    char sexo[MAX_C];
} CADASTRO;

void leituraCadastro(CADASTRO *vetor);
void pesquisaIdade(CADASTRO *vetor);
void pesquisaSexo(CADASTRO *vetor);
void pesquisaSalario(CADASTRO *vetor);
void pesquisaIdentidade(CADASTRO *vetor);
void imprimeStruct(CADASTRO *vetor, int i);
void limpaJanela();
void paraJanela();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    CADASTRO vetor[MAX];
    int menu;
    leituraCadastro(vetor);
    do
    {
        limpaJanela();
        printf("MENU\n");
        printf("1 - Pesquisa pela maior idade.\n");
        printf("2 - Pesquisa pelo sexo masculino.\n");
        printf("3 - Pesquisa pelo salário maior que R$ 1000,00.\n");
        printf("4 - Pesquisa pela número da identidade.\n");
        printf("5 - Sair.\n");
        scanf("%d", &menu);
        getchar();
        switch (menu)
        {
        case 1:
            pesquisaIdade(vetor);
            break;
        case 2:
            pesquisaSexo(vetor);
            break;
        case 3:
            pesquisaSalario(vetor);
            break;
        case 4:
            pesquisaIdentidade(vetor);
            break;
        case 5:
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    } while (menu != 5);
    return 0;
}
void leituraCadastro(CADASTRO *ptr)
{
    for (int i = 0; i < MAX; i++)
    {
        limpaJanela();
        printf("%dº CADASTRO: \n", i + 1);
        printf("Informe o nome: ");
        fgets(ptr[i].nome, MAX_C, stdin);
        printf("Informe o número da identidade: ");
        fgets(ptr[i].identidade, 11, stdin);
        printf("Informe o CPF: ");
        fgets(ptr[i].cpf, 16, stdin);
        printf("Informe o telefone [DDD antes do número]: ");
        fgets(ptr[i].telefone, 16, stdin);
        printf("Informe o endereço [CEP]: ");
        scanf("%[^\n]", ptr[i].endereco.cep);
        getchar();
        printf("Informe o endereço [ESTADO]: ");
        scanf("%[^\n]", ptr[i].endereco.estado);
        getchar();
        printf("Informe o endereço [CIDADE]: ");
        scanf("%[^\n]", ptr[i].endereco.cidade);
        getchar();
        printf("Informe o endereço [BAIRRO]: ");
        scanf("%[^\n]", ptr[i].endereco.bairro);
        getchar();
        printf("Informe o endereço [RUA]: ");
        scanf("%[^\n]", ptr[i].endereco.rua);
        getchar();
        printf("Informe a idade: ");
        scanf("%d", &ptr[i].idade);
        getchar();
        printf("Informe o salário: ");
        scanf("%lf", &ptr[i].salario);
        getchar();
        printf("Informe o estado civil: ");
        fgets(ptr[i].estado_civil, MAX_C, stdin);
        printf("Informe o sexo [Masculino, Feminino ou Outro]: ");
        fgets(ptr[i].sexo, MAX_C, stdin);
    }
}
void pesquisaIdade(CADASTRO *ptr)
{
    int posicao;
    for (int i = 0; i < MAX - 1; i++)
        if (ptr[i].idade > ptr[i + 1].idade)
            posicao = i;
    limpaJanela();
    imprimeStruct(ptr, posicao);
    paraJanela();
}
void pesquisaSexo(CADASTRO *ptr)
{
    limpaJanela();
    for (int i = 0; i < MAX; i++)
        if (strcmp(ptr[i].sexo, "Masculino\n") == 0)
        {
            imprimeStruct(ptr, i);
            printf("\n");
        }
    paraJanela();
}
void pesquisaSalario(CADASTRO *ptr)
{
    limpaJanela();
    for (int i = 0; i < MAX; i++)
        if (ptr[i].salario > 1000)
        {
            imprimeStruct(ptr, i);
            printf("\n");
        }
    paraJanela();
}
void pesquisaIdentidade(CADASTRO *ptr)
{
    char aux[11];
    limpaJanela();
    printf("Informe a identidade a ser pesquisada [X.XXX.XXX]: ");
    fgets(aux, 11, stdin);
    limpaJanela();
    for (int i = 0; i < MAX; i++)
        if (strcmp(ptr[i].identidade, aux) == 0)
        {
            imprimeStruct(ptr, i);
            printf("\n");
        }
    paraJanela();
}
void imprimeStruct(CADASTRO *ptr, int i)
{
    printf("Nome: %s", ptr[i].nome);
    printf("Número de Identidade: %s", ptr[i].identidade);
    printf("CPF: %s", ptr[i].cpf);
    printf("Telefone: %s", ptr[i].telefone);
    printf("Endereço: %s, ", ptr[i].endereco.cep);
    printf("%s ", ptr[i].endereco.rua);
    printf("%s, ", ptr[i].endereco.bairro);
    printf("%s - ", ptr[i].endereco.cidade);
    printf("%s\n", ptr[i].endereco.estado);
    printf("Idade: %d anos\n", ptr[i].idade);
    printf("Salario: R$ %.2lf\n", ptr[i].salario);
    printf("Estado Civil: %s", ptr[i].estado_civil);
    printf("Sexo: %s", ptr[i].sexo);
}
void limpaJanela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void paraJanela()
{
#ifdef _WIN32
    system("pause");
#else
    getchar();
#endif
}
//Texto para o teste (os dados são aleatórios)
/*
Adenor Gerisvaldo
5.674.215
045.657.981-97
(61)98504-6133
72754-156
Distrito Federal
Brazlândia
Norte
03
35
3567.75
Casado
Masculino
Maria Joséfina
8.617.594
345.678.912-05
(61)99657-4284
72564-453
Distrito Federal
Brazlândia
Sul
04
44
7549.56
Casada
Feminino
João da Costa
7.564.123
753.159.456-99
(61)99574-3622
72546-010
Distrito Federal
Brazlândia
Tradicional
77
20
654.13
Solteiro
Outro
Magnaldo Prado
5.489.621
761.489.531-08
(61)98574-6852
75794-414
Distrito Federal
Brazlândia
Vila São José
34
56
10567.88
Casado
Masculino
Gustavo Fernandes de Bragança
1.578.956
654.123.789-55
(61)99678-3546
79846-123
Distrito Federal
Brazlândia
Veredas
5
10
0
Solteiro
Masculino

*/