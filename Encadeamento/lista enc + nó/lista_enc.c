#include "lista_enc.h"
#include <stdio.h>
#include <stdlib.h>

void lst_init(lst_ptr * l)
{
    if ((*l = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria!\n");
        exit(1);
    }
    (*l)->prox = NULL;
}

bool lst_acessar(lst_ptr l, int k, lst_info * val)
{
    int i;
    l = l->prox; // pula o nó cabeça
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
    l = l->prox; // pula o nó cabeça
    for (i = 0; i < k && l != NULL; i++) {
        l = l->prox;
    }
    if (l == NULL) {
        return false;
    }
    l->dado = val;
    return true;
}

bool lst_inserir(lst_ptr l, int k, lst_info val)
{
    lst_ptr n;
    int i;
    for (i = 0; i < k && l != NULL; i++) {
        l = l->prox;
    }
    if (l == NULL) {
        return false;
    }
    if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL) {
         return false;
    }
    n->dado = val;
    n->prox = l->prox;
    l->prox = n;
    return true;
}

bool lst_remover(lst_ptr l, int k, lst_info * val)
{
    if (k >= 0) {
        int i;
        for (i = 0; i < k && l->prox != NULL; i++) {
            l = l->prox;
        }
        if (l->prox != NULL) {
            lst_ptr n = l->prox;
            *val = n->dado;
            l->prox = n->prox;
            free(n);
            return true;
        }
    }
    return false;
}


int lst_tamanho(lst_ptr l)
{
    int i;
    l = l->prox;
    for (i = 0; l != NULL; i++) {
        l = l->prox;
    }
    return i;
}

lst_ptr lst_procurar(lst_ptr l, lst_info val)
{
    l = l->prox;
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
    l = l->prox;
    while(l != NULL) {
        printf("%d,", l->dado);
        l = l->prox;
    }
    printf("\b ]\n");
}
