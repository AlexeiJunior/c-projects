#include "pilha_enc.h"
#include <stdio.h>
#include <stdlib.h>

void stack_init(stack_ptr * topo)
{
    *topo = NULL;
}

bool stack_isempty(stack_ptr topo)
{
    return topo == NULL;
}

void push(stack_ptr * topo, stack_info x)
{
    stack_ptr p;
    if ((p = (stack_ptr) malloc(sizeof(struct stack_no))) == NULL) {
        fprintf(stderr, "Pilha cheia!\n");
        exit(1);
    }
    p->dado = x;
    p->prox = *topo;
    *topo = p;
}

stack_info pop(stack_ptr * topo)
{
    if (!stack_isempty(*topo)) {
        stack_ptr p = *topo;
        stack_info x = p->dado;
        *topo = p->prox;
        free(p);
        return x;
    }
    else {
        fprintf(stderr, "Pilha vazia!\n");
        exit(1);
    }
}

stack_info top(stack_ptr topo)
{
    if (!stack_isempty(topo)) {
        return topo->dado;
    }
    else {
        fprintf(stderr, "Pilha vazia!\n");
        exit(1);
    }
}

void stack_kill(stack_ptr * topo)
{
    stack_ptr p;
    while (*topo != NULL) {
        p = *topo;
        *topo = p->prox;
        free(p);
    }
}
