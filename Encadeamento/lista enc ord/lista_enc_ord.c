/* lista_enc_ord.c
 * Implementa as operações sobre o TAD lista ordenada representada de forma encadeada */

#include "lista_enc_ord.h"
#include <stdlib.h>
#include <stdio.h>

void lst_init(lst_ptr * l)
{
    *l = NULL;
}

void lst_ins(lst_ptr * l, lst_info x)
{
    lst_ptr n;
    if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL)
    {
        fprintf(stderr, "Lista cheia!\n");
        exit(1);
    }
    n->dado = x;
    if (*l == NULL || x <= (*l)->dado)
    {
        n->prox = *l;
        *l = n;
    }
    else
    {
        lst_ptr p = *l;
        while (p->prox != NULL && x > p->prox->dado)
        {
            p = p->prox;
        }
        n->prox = p->prox;
        p->prox = n;
    }
}

bool lst_rem(lst_ptr * l, lst_info x)
{
    if (*l == NULL || x < (*l)->dado)
    {
        return false;
    }
    else
    {
        lst_ptr p = *l;
        if (x == (*l)->dado)   // remoção do 1º da lista
        {
            *l = p->prox;
            free(p);
            return true;
        }
        while (p->prox != NULL && x > p->prox->dado)
        {
            p = p->prox;
        }
        if (p->prox != NULL && x == p->prox->dado)
        {
            lst_ptr n = p->prox;
            p->prox = n->prox;
            free(n);
            return true;
        }
        return false;
    }
}

lst_ptr lst_find(lst_ptr l, lst_info x)
{
    while (l != NULL && x > l->dado)
    {
        l = l->prox;
    }
    if (l != NULL && x == l->dado)
    {
        return l;
    }
    return NULL;
}

void lst_print(lst_ptr l)
{
    printf("[ ");
    while (l != NULL)
    {
        printf("%d,", l->dado);
        l = l->prox;
    }
    printf("\b ]\n");
}

void lst_kill(lst_ptr * l)
{
    lst_ptr p;
    while (*l != NULL)
    {
        p = *l;
        *l = p->prox;
        free(p);
    }
}

int lst_occurs(lst_ptr l, lst_info x)
{
    int cont = 0;
    while (l != NULL && l->dado <= x)
    {
        if (l->dado == x)
        {
            cont++;
        }
        l = l->prox;
    }
    return cont;
}

int lst_size(lst_ptr l)
{
    int cont = 0;
    while (l != NULL)
    {
        cont++;
        l = l->prox;
    }
    return cont;
}

int lst_rem_all(lst_ptr * l, lst_info x)
{
    int cont = 0;
    if (*l == NULL || x < (*l)->dado)
    {
        return cont;
    }
    else
    {
        lst_ptr p;
        if (x == (*l)->dado)   // remoção do 1º da lista
        {
            while (*l != NULL && x == (*l)->dado)
            {
                p = *l;
                *l = p->prox;
                free(p);
                cont++;
            }
        }
        else
        {
            p = *l;
            lst_ptr n;
            while (p->prox != NULL && x > p->prox->dado)
            {
                p = p->prox;
            }
            while (p->prox != NULL && x == p->prox->dado)
            {
                n = p->prox;
                p->prox = n->prox;
                free(n);
                cont++;
            }
        }
        return cont;
    }
}

lst_ptr lst_merge(lst_ptr l1, lst_ptr l2)
{
    lst_ptr l3, n, p;
    lst_init(&l3);
    p = l3;
    while (l1 != NULL && l2 != NULL)
    {
        if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL)
        {
            fprintf(stderr, "Erro de alocacao de memoria!\n");
            exit(1);
        }
        n->prox = NULL;
        if (l1->dado < l2->dado)
        {
            n->dado = l1->dado;
            if (p == NULL)
            {
                l3 = n;
            }
            else
            {
                p->prox = n;
            }
            l1 = l1->prox;
        }
        else
        {
            n->dado = l2->dado;
            if (p == NULL)
            {
                l3 = n;
            }
            else
            {
                p->prox = n;
            }
            l2 = l2->prox;
        }
        p = n;
    }
    while (l1 != NULL)
    {
        if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL)
        {
            fprintf(stderr, "Erro de alocacao de memoria!\n");
            exit(1);
        }
        n->prox = NULL;
        n->dado = l1->dado;
        p->prox = n;
        p = n;
        l1 = l1->prox;
    }
    while (l2 != NULL)
    {
        if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL)
        {
            fprintf(stderr, "Erro de alocacao de memoria!\n");
            exit(1);
        }
        n->prox = NULL;
        n->dado = l2->dado;
        p->prox = n;
        p = n;
        l2 = l2->prox;
    }
    return l3;
}

bool lst_equals(lst_ptr l1, lst_ptr l2)
{
    while (l1 != NULL && l2 != NULL && l1->dado == l2->dado) {
        l1 = l1->prox;
        l2 = l2->prox;
    }
    return (l1 == NULL && l2 == NULL);
}
