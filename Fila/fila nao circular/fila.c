#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void queue_init(fila * f)
{
    f->comeco = f->final = 0;
}

bool queue_isempty(fila f)
{
    return f.comeco == f.final;
}

bool queue_isfull(fila f)
{
    return (f.final - f.comeco == MAX);
}

void enqueue(fila * f, queue_info x)
{
    if (!queue_isfull(*f)) {
        if (f->final == MAX) { // deslocamento
            int i;
            for (i = 0; i < f->final - f->comeco; i++) {
                f->itens[i] = f->itens[f->comeco + i];
            }
            f->final = i; // f->final = f->final - f->comeco;
            f->comeco = 0;
        }
        f->itens[f->final++] = x;
    }
    else {
        fprintf(stderr, "Fila cheia!\n");
        exit(1);
    }
}

queue_info dequeue(fila * f)
{
    if (!queue_isempty(*f)) {
        return f->itens[f->comeco++];
    }
    else {
        fprintf(stderr, "Fila vazia!\n");
        exit(1);
    }
}

void queue_print(fila f)
{
    int i;
    printf("[ ");
    for (i = f.comeco; i < f.final; i++) {
        printf("%d,", f.itens[i]);
    }
    printf("\b ]\n");
}
