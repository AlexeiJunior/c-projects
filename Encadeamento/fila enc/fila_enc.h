/* fila_enc.h
 * Definição do TAD fila representado de forma encadeada e protótipo de
 * suas operações */

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

/* função que inicializa a fila */
void queue_init(fila *);

/* função que verifica se a fila está vazia */
bool queue_isempty(fila);

/* função que insere um elemento no final da fila */
void enqueue(fila *, queue_info);

/* função que remove e devolve o elemento do começo da fila */
queue_info dequeue(fila *);

/* função que imprime o conteúdo da fila */
void queue_print(fila);

/* função que destrói a fila */
void queue_kill(fila *);

#endif // _FILA_ENC_H
