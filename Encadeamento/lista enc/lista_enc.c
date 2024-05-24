#include "lista_enc.h"
#include <stdio.h>
#include <stdlib.h>

void lst_init(lst_ptr * l)
{
    *l = NULL;
}

bool lst_acessar(lst_ptr l, int k, lst_info * val)
{
    int i;
    for (i = 0; i < k && l != NULL; i++) {
        l = l->prox;
    }
    if (l == NULL) {
        return false;
    }
    *val = l->dado;
    return true;
}

bool lst_alterar(lst_ptr l, int k, lst_info val)
{
    int i;
    for (i = 0; i < k && l != NULL; i++) {
        l = l->prox;
    }
    if (l == NULL) {
        return false;
    }
    l->dado = val;
    return true;
}

bool lst_inserir(lst_ptr * l, int k, lst_info val)
{
    lst_ptr n;
    if (k == 0) { // inserção n 1ª posição da lista
        if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL) {
            return false;
        }
        n->dado = val;
        n->prox = *l;
        *l = n;
    }
    else {
        int i;
        lst_ptr p = *l;
        for (i = 0; i < k-1 && p != NULL; i++) {
            p = p->prox;
        }
        if (p == NULL) {
            return false;
        }
        if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL) {
            return false;
        }
        n->dado = val;
        n->prox = p->prox;
        p->prox = n;
    }
    return true;
}

bool lst_remover(lst_ptr * l, int k, lst_info * val)
{
    if (*l != NULL && k >= 0) {
        lst_ptr p = *l;
        if (k == 0) { // remoção do 1º
            *val = p->dado;
            *l = p->prox;
            free(p);
            return true;
        }
        int i;
        for (i = 0; i < k-1 && p->prox != NULL; i++) {
            p = p->prox;
        }
        if (p->prox != NULL) {
            lst_ptr n = p->prox;
            *val = n->dado;
            p->prox = n->prox;
            free(n);
            return true;
        }
    }
    return false;
}


int lst_tamanho(lst_ptr l)
{
    int i;
    for (i = 0; l != NULL; i++) {
        l = l->prox;
    }
    return i;
}

lst_ptr lst_procurar(lst_ptr l, lst_info val)
{
    while (l != NULL)  {
        if (l->dado == val) {
            return l;
        }
        l = l->prox;
    }
    return NULL;
}

void lst_imprimir(lst_ptr l)
{
    printf("[ ");
    while(l != NULL) {
        printf("%d,", l->dado);
        l = l->prox;
    }
    printf("\b ]\n");
}
