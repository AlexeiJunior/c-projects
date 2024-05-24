/* deque.h
 * Definição do TAD deque e protótipos de suas operações
 *
 * Ciro Cirne Trindade
 * 24/03/2015
 */

#ifndef _DEQUE_H
#define _DEQUE_H

#include <stdbool.h>

#define MAX 10
typedef int deque_info;
typedef struct {
	deque_info itens[MAX];
	int esq; // índice para o último inserido pela esquerda
	int dir; // índice para o último inserido pela direita
} deque;

/* função que inicializa um deque no estado vazio */
void deque_init(deque *);

/* função que verifica se o deque está vazio */
bool deque_isempty(deque);

/* função que verifica se o deque está cheio */
bool deque_isfull(deque);

/* função que insere um novo elemento no deque pela esquerda */
void deque_ins_esq(deque *, deque_info);

/* função que insere um novo elemento no deque pela direita */
void deque_ins_dir(deque *, deque_info);

/* função que remove um elemento do deque pela esquerda */
deque_info deque_rem_esq(deque *);

/* função que remove um elemento do deque pela direita */
deque_info deque_rem_dir(deque *);

/* função que imprime o conteúdo do deque */
void deque_print(deque);

#endif
