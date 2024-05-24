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
        f->itens[f->final++ % MAX] = x; //resto de divisão só pode dar de 0 ate MAX-1;
    }
    else {
        fprintf(stderr, "Fila cheia!\n");
        exit(1);
    }
}

void queue_fura_fila(fila * f, queue_info x)
{
    if (!queue_isfull(*f)) {
        f->comeco--;
        if (f->comeco < 0) {
            f->comeco += MAX;
            f->final += MAX;
        }
        f->itens[f->comeco % MAX] = x;
    }
    else {
        fprintf(stderr, "Fila cheia!\n");
        exit(1);
    }
}

queue_info dequeue(fila * f)
{
    if (!queue_isempty(*f)) {
        return f->itens[f->comeco++ % MAX]; //resto de divisão só pode dar de 0 ate MAX-1;
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
        printf("%d,", f.itens[i % MAX]);
    }
    printf("\b ]\n");
}

bool queueContem(fila f, queue_info x)
{
    if (!queue_isempty(f)) {
        int i;
        for (i = f.comeco; i < f.final; i++) {
            if(f.itens[i % MAX] == x){
                return true;
            }
        }
        return false;
    }
    else {
        fprintf(stderr, "Fila vazia!\n");
        exit(1);
    }
}
