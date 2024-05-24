/* abb.c
 * Implementação das operações realizadas sobre o TAD que representa
 * uma árvore binária de busca */

#include "abb.h"
#include <stdlib.h>
#include <stdio.h>

void tree_init(arvbin * t)
{
    *t = NULL;
}

void em_ordem(arvbin t)
{
    if (t != NULL) {
        em_ordem(t->esq);
        printf("%d ", t->dado);
        em_ordem(t->dir);
    }
}

void pos_ordem(arvbin t)
{
    if (t != NULL) {
        pos_ordem(t->esq);
        pos_ordem(t->dir);
        printf("%d ", t->dado);
    }
}

void pre_ordem(arvbin t)
{
    if (t != NULL) {
        printf("%d ", t->dado);
        pre_ordem(t->esq);
        pre_ordem(t->dir);
    }
}

void tree_ins(arvbin * t, tree_info x)
{
    if (*t == NULL) {
        if ((*t = (arvbin) malloc(sizeof(struct no_arvbin))) == NULL) {
            fprintf(stderr, "Erro de alocacao de memoria!\n");
            exit(1);
        }
        (*t)->dado = x;
        (*t)->esq = (*t)->dir = NULL;
    }
    else {
        if (x < (*t)->dado) {
            tree_ins(&(*t)->esq, x);
        }
        else {
            tree_ins(&(*t)->dir, x);
        }
    }
}

arvbin tree_find(arvbin t, tree_info x)
{
    if (t == NULL) {
        return NULL;
    }
    if (x == t->dado) {
        return t;
    }
    if (x < t->dado) {
        return tree_find(t->esq, x);
    }
    return tree_find(t->dir, x);
}

bool tree_rem(arvbin * t, tree_info x)
{
    if (*t == NULL) {
        return false;
    }
    if (x == (*t)->dado) {
        arvbin p = *t;
        if ((*t)->esq == NULL) {
            *t = (*t)->dir;
        }
        else {
            if ((*t)->dir == NULL) {
                *t = (*t)->esq;
            }
            else {
                p = getmin(&(*t)->dir);
                (*t)->dado = p->dado;
            }
        }
        free(p);
        return true;
    }
    if (x < (*t)->dado) return tree_rem(&(*t)->esq, x);
    return tree_rem(&(*t)->dir, x);
}

arvbin getmin(arvbin * t)
{
    if ((*t)->esq == NULL) {
        arvbin p = *t;
        *t = (*t)->dir;
        return p;
    }
    return getmin(&(*t)->esq);
}
