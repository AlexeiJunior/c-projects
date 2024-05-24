/* pilha_enc.h
 * Defini��o do TAD que representa uma pilha encadeada e os prot�tipos de suas opera��es */

#ifndef _PILHA_ENC_H
#define _PILHA_ENC_H

#include <stdbool.h>

typedef int stack_info;
typedef struct stack_no * stack_ptr;
struct stack_no {
    stack_info dado;
    stack_ptr prox;
};

/* fun��o que inicializa a pilha */
void stack_init(stack_ptr *);

/* fun��o que verifica se a pilha est� vazia */
bool stack_isempty(stack_ptr);

/* fun��o que empilha um valor */
void push(stack_ptr *, stack_info);

/* fun��o que desempilha o valor do topo da pilha e devolve seu valor */
stack_info pop(stack_ptr *);

/* fun��o que devolve o valor do elemento do topo da pilha */
stack_info top(stack_ptr);

/* fun��o que destr�io a pilha */
void stack_kill(stack_ptr *);

#endif // _PILHA_ENC_H
