#include <stdio.h>
#include "abb.h"

int main()
{
    arvbin t;
    tree_info x;
    tree_init(&t);

    printf("Insercao (-1 p/ terminar): ");
    scanf("%d", &x);
    while (x != -1) {
        tree_ins(&t, x);
        printf("Insercao (-1 p/ terminar): ");
        scanf("%d", &x);
    }
    printf("Arvore: ");
    em_ordem(t);

    printf("\n\nBusca (-1 p/ terminar): ");
    scanf("%d", &x);
    while (x != -1) {
        if (tree_find(t, x) != NULL) {
            puts("Encontrado");
        }
        else {
            puts("Nao encontrado");
        }
        printf("Busca (-1 p/ terminar): ");
        scanf("%d", &x);
    }

    printf("\nRemocao (-1 p/ terminar): ");
    scanf("%d", &x);
    while (x != -1) {
        if (tree_rem(&t, x)) {
            puts("Removido");
            em_ordem(t);
        }
        else {
            puts("Nao encontrado");
        }
        printf("\nRemocao (-1 p/ terminar): ");
        scanf("%d", &x);
    }
    return 0;
}
