/* fila.h
 * Defini��o do TAD fila e prot�tipo de suas opera��es */

#ifndef _FILA_H
#define _FILA_H
#include <stdbool.h>

#define MAX 5
typedef int queue_info;
typedef struct {
    int comeco;
    int final;
    queue_info itens[MAX];
} fila;

/* fun��o que inicializa a fila no estado vazio */
void queue_init(fila *);

/* fun��o que verifica se a fila est� vazia */
bool queue_isempty(fila);

/* fun��o que verifica sse a fila est� cheia */
bool queue_isfull(fila);

/* fun��o que insere um novo elemento do final da fila */
void enqueue(fila *, queue_info);

/* fun��o que insere um novo elemento no come�o da fila */
void queue_fura_fila(fila *, queue_info);

/* fun��o remove e devolve o elemento do come�o da fila */
queue_info dequeue(fila *);

/* fun��o que imprime o conte�do da fila */
void queue_print(fila);

bool queueContem(fila, queue_info);
#endif // _FILA_H
