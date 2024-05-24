/* pilha.h
 * Definição do TAD pilha e protótipo de suas operações */

#ifndef _PILHA_H
#define _PILHA_H

#include <stdbool.h>

#define MAX 10
typedef int stack_info;
typedef struct {
    stack_info itens[MAX];
    int topo;
} pilha;

/* função que iniializa a pilha no estado vazio */
void stack_init(pilha *);

/* função que verifica se a pilha está vazia */
bool stack_isempty(pilha);

/* função que verifica se a pilha está cheia */
bool stack_isfull(pilha);

/* função que insere um valor no topo da pilha */
void push(pilha *, stack_info);

/* função que insere um valor no topo da pilha e sinaliza através do seu
 * 3º parâmetro a ocorrência de um overflow (estouro da pilha) */
void push_and_test(pilha *, stack_info, bool *);

/* função que remove e devolve o valor do elemento do topo da pilha */
stack_info pop(pilha *);

/* função que remove e devolve o valor do elemento do topo da pilha
 * e sinaliza através do seu 2º parâmetro um underflow (pilha vazia) */
stack_info pop_and_test(pilha *, bool *);

/* função que devolve o elemento do topo da pilha */
stack_info top(pilha);

/* função que devolve o elemento do topo da pilha e sinaliza
 * através do seu 2º parâmetro um underflow (pilha vazia) */

stack_info top_and_test(pilha, bool *);

#endif // _PILHA_H
