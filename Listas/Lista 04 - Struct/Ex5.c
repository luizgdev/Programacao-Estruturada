#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct vetor
{
    int a;
    int b;
    int c;
};

void leituraVetores(struct vetor *A, struct vetor *B);
void somaVetores(struct vetor *A, struct vetor *B, struct vetor *vetor_resultado);
void mostraVetorResultado(struct vetor vetor_resultado);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct vetor A;
    struct vetor B;
    struct vetor vetor_resultado;
    leituraVetores(&A, &B);
    somaVetores(&A, &B, &vetor_resultado);
    mostraVetorResultado(vetor_resultado);
    return 0;
}
void leituraVetores(struct vetor *A, struct vetor *B)
{
    printf("Informe o primeiro vetor com 3 posições: ");
    scanf("%d %d %d", &A->a, &A->b, &A->c);
    printf("Informe o segundo vetor com 3 posições: ");
    scanf("%d %d %d", &B->a, &B->b, &B->c);
}
void somaVetores(struct vetor *A, struct vetor *B, struct vetor *vetor_resultado)
{
    vetor_resultado->a = (A->a + B->a);
    vetor_resultado->b = (A->b + B->b);
    vetor_resultado->c = (A->c + B->c);
}
void mostraVetorResultado(struct vetor vetor_resultado)
{
    printf("Vetor resultado = (%d, %d, %d)\n", vetor_resultado.a, vetor_resultado.b, vetor_resultado.c);
}