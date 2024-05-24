/* pilha_enc.h
 * Definição do TAD que representa uma pilha encadeada e os protótipos de suas operações */

#ifndef _PILHA_ENC_H
#define _PILHA_ENC_H

#include <stdbool.h>

typedef int stack_info;
typedef struct stack_no * stack_ptr;
struct stack_no {
    stack_info dado;
    stack_ptr prox;
};

/* função que inicializa a pilha */
void stack_init(stack_ptr *);

/* função que verifica se a pilha está vazia */
bool stack_isempty(stack_ptr);

/* função que empilha um valor */
void push(stack_ptr *, stack_info);

/* função que desempilha o valor do topo da pilha e devolve seu valor */
stack_info pop(stack_ptr *);

/* função que devolve o valor do elemento do topo da pilha */
stack_info top(stack_ptr);

/* função que destróio a pilha */
void stack_kill(stack_ptr *);

#endif // _PILHA_ENC_H
