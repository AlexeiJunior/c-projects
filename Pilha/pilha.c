/* pilha.c
 * Implementação das operações realizadas sobre o TAD pilha */

#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void stack_init(pilha * p)
{
    p->topo = -1;
}

bool stack_isempty(pilha p)
{
    return (p.topo == -1);
}

bool stack_isfull(pilha p)
{
    return (p.topo == MAX - 1);
}

void push(pilha * p, stack_info val)
{
    if (!stack_isfull(*p)) {
        /*
        p->topo++;
        p->itens[p->topo] = val;
        */
        p->itens[++p->topo] = val;
    }
    else {
        fprintf(stderr, "Estouro da pilha!\n");
        exit(1);
    }
}

void push_and_test(pilha * p, stack_info val, bool * over)
{
    if (!stack_isfull(*p)) {
        p->itens[++p->topo] = val;
        *over = false;
    }
    else {
        *over = true; // sinaliza o overflow
    }
}

stack_info pop(pilha * p)
{
    if (!stack_isempty(*p)) {
        /*
        stack_info val = p->itens[p->topo];
        p->topo--;
        return val;
        */
        return p->itens[p->topo--];
    }
    else {
        fprintf(stderr, "Pilha vazia!\n");
        exit(1);
    }
}

stack_info pop_and_test(pilha * p, bool * under)
{
    if (!stack_isempty(*p)) {
        *under = false;
        return p->itens[p->topo--];
    }
    *under = true;
}

stack_info top(pilha p)
{
    if (!stack_isempty(p)) {
        return p.itens[p.topo];
    }
    else {
        fprintf(stderr, "Pilha vazia!\n");
        exit(1);
    }
}

stack_info top_and_test(pilha p, bool * under)
{
    if (!stack_isempty(p)) {
        *under = false;
        return p.itens[p.topo];
    }
    *under = true;
}
