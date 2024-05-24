/* fila_enc.c
 * Implementação das operações realizadas sobre o TAD fila representado
 * de forma encadeada */

#include "fila_enc.h"
#include <stdio.h>
#include <stdlib.h>

void queue_init(fila * f)
{
    f->comeco = f->final = NULL;
}

bool queue_isempty(fila f)
{
    return f.comeco == NULL && f.final == NULL;
}

void enqueue(fila * f, queue_info x)
{
    queue_ptr p;
    if ((p = (queue_ptr) malloc(sizeof(struct queue_no)))== NULL) {
        fprintf(stderr, "Fila cheia!\n");
        exit(1);
    }
    p->dado = x;
    p->prox = NULL;
    if (queue_isempty(*f)) {
        f->comeco = p;
    }
    else {
        f->final->prox = p;
    }
    f->final = p;
}

queue_info dequeue(fila * f)
{
    if (!queue_isempty(*f)) {
        queue_ptr p = f->comeco;
        queue_info x = f->comeco->dado;
        if (f->comeco == f->final) { // só tem um elemento
            f->final = NULL;
        }
        f->comeco = f->comeco->prox;
        free(p);
        return x;
    }
    else {
        fprintf(stderr, "Fila vazia!\n");
        exit(1);
    }
}

void queue_print(fila f)
{
    printf("[ ");
    while (f.comeco != NULL) {
        printf("%d,", f.comeco->dado);
        f.comeco = f.comeco->prox;
    }
    printf("\b ]\n");
}

void queue_kill(fila * f)
{
    queue_ptr p;
    while (f->comeco != NULL) {
        p = f->comeco;
        f->comeco = p->prox;
        free(p);
    }
    f->final = NULL;
}
