/* pilha.h
 * Defini��o do TAD pilha e prot�tipo de suas opera��es */

#ifndef _PILHA_H
#define _PILHA_H

#include <stdbool.h>

#define MAX 10
typedef int stack_info;
typedef struct {
    stack_info itens[MAX];
    int topo;
} pilha;

/* fun��o que iniializa a pilha no estado vazio */
void stack_init(pilha *);

/* fun��o que verifica se a pilha est� vazia */
bool stack_isempty(pilha);

/* fun��o que verifica se a pilha est� cheia */
bool stack_isfull(pilha);

/* fun��o que insere um valor no topo da pilha */
void push(pilha *, stack_info);

/* fun��o que insere um valor no topo da pilha e sinaliza atrav�s do seu
 * 3� par�metro a ocorr�ncia de um overflow (estouro da pilha) */
void push_and_test(pilha *, stack_info, bool *);

/* fun��o que remove e devolve o valor do elemento do topo da pilha */
stack_info pop(pilha *);

/* fun��o que remove e devolve o valor do elemento do topo da pilha
 * e sinaliza atrav�s do seu 2� par�metro um underflow (pilha vazia) */
stack_info pop_and_test(pilha *, bool *);

/* fun��o que devolve o elemento do topo da pilha */
stack_info top(pilha);

/* fun��o que devolve o elemento do topo da pilha e sinaliza
 * atrav�s do seu 2� par�metro um underflow (pilha vazia) */

stack_info top_and_test(pilha, bool *);

#endif // _PILHA_H
