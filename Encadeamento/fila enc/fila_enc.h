/* fila_enc.h
 * Defini��o do TAD fila representado de forma encadeada e prot�tipo de
 * suas opera��es */

#ifndef _FILA_ENC_H
#define _FILA_ENC_H

#include <stdbool.h>

typedef int queue_info;
typedef struct queue_no * queue_ptr;
struct queue_no {
    queue_info dado;
    queue_ptr prox;
};
typedef struct {
    queue_ptr comeco;
    queue_ptr final;
} fila;

/* fun��o que inicializa a fila */
void queue_init(fila *);

/* fun��o que verifica se a fila est� vazia */
bool queue_isempty(fila);

/* fun��o que insere um elemento no final da fila */
void enqueue(fila *, queue_info);

/* fun��o que remove e devolve o elemento do come�o da fila */
queue_info dequeue(fila *);

/* fun��o que imprime o conte�do da fila */
void queue_print(fila);

/* fun��o que destr�i a fila */
void queue_kill(fila *);

#endif // _FILA_ENC_H
