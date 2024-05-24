#include <stdio.h>
#include "pilha.h"

int main()
{
    pilha p;
    int n;
    bool falhou = false;

    stack_init(&p);
    printf("Informe um numero positivo na base decimal: ");
    scanf("%d", &n);
    while (n > 0 && !falhou) {
        push_and_test(&p, n % 2, &falhou);
        n /= 2;
    }
    if (falhou) {
        printf("Erro: numero muito grande, nao foi possivel converte-lo para binario\n");
    }
    else {
        printf("Valor na base binaria: ");
        while (!stack_isempty(p)) {
            printf("%d", pop(&p));
        }
        printf("\n");
    }
    return 0;
}
