/* fila.h
 * Definição do TAD fila e protótipo de suas operações */

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

/* função que inicializa a fila no estado vazio */
void queue_init(fila *);

/* função que verifica se a fila está vazia */
bool queue_isempty(fila);

/* função que verifica sse a fila está cheia */
bool queue_isfull(fila);

/* função que insere um novo elemento do final da fila */
void enqueue(fila *, queue_info);

/* função que insere um novo elemento no começo da fila */
void queue_fura_fila(fila *, queue_info);

/* função remove e devolve o elemento do começo da fila */
queue_info dequeue(fila *);

/* função que imprime o conteúdo da fila */
void queue_print(fila);

bool queueContem(fila, queue_info);
#endif // _FILA_H
