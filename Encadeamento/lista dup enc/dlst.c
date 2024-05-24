/* dlst.c
 * Implementa as operações sobre o TAD lista ordenada ducplamente encadeada com nó cabeça */

#include "dlst.h"
#include <stdio.h>
#include <stdlib.h>

void dlst_init(dlst_ptr * l)
{
    if((*l = (dlst_ptr) malloc(sizeof(struct dlst_no))) == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria!\n");
        exit(1);
    }
    (*l)->prox = (*l)->ant = *l;
}

void dlst_inserir(dlst_ptr l, dlst_info x)
{
    dlst_ptr n, p;
    if ((n = (dlst_ptr) malloc(sizeof(struct dlst_no))) == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria!\n");
        exit(1);
    }
    n->dado = x;
    p = l;
    while (p->prox != l && x > p->prox->dado) {
        p = p->prox;
    }
    n->prox = p->prox;
    n->ant = p;
    p->prox->ant = n;
    p->prox = n;
}

bool dlst_remover(dlst_ptr l, dlst_info x)
{
    dlst_ptr p = l->prox;
    while (p != l && x > p->dado) {
        p = p->prox;
    }
    if (p != l && x == p->dado) {
        p->prox->ant = p->ant;
        p->ant->prox = p->prox;
        free(p);
        return true;
    }
    return false;
}

void dlst_print_cresc(dlst_ptr l)
{
    dlst_ptr p = l->prox;
    printf("[ ");
    while (p != l) {
        printf("%d,", p->dado);
        p = p->prox;
    }
    printf("\b ]\n");
}

void dlst_printf_dec(dlst_ptr l)
{
    dlst_ptr p = l->ant;
    printf("[ ");
    while (p != l) {
        printf("%d,", p->dado);
        p = p->ant;
    }
    printf("\b ]");
}

dlst_info dlst_delete_last(dlst_ptr l)
{
    if (l->ant != l->prox) {
        dlst_ptr p = l->ant;
        dlst_info x = p->dado;
        p->ant->prox = l;
        l->ant = p->ant;
        free(p);
        return x;
    }
    else {
        fprintf(stderr, "Lista vazia!\n");
        exit(1);
    }
}

void dlst_reverse(dlst_ptr l)
{
    dlst_ptr p = l, aux;
    do {
        aux = p->prox;
        p->prox = p->ant;
        p->ant = aux;
        p = p->ant;
    } while (p != l);
}
