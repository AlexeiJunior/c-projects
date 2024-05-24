#include "fpa.h"
#include <stdio.h>
#include <stdlib.h>

void fpa_init(fpa * f)
{
    f->comeco = f->final = 0;
}

bool fpa_isempty(fpa f)
{
    return f.comeco == f.final;
}

bool fpa_isfull(fpa f)
{
    return (f.final - f.comeco == MAX);
}

void fpa_inserir(fpa * f, fpa_info x)
{
    if (!fpa_isfull(*f)) {
        f->itens[f->final++ % MAX] = x;
    }
    else {
        fprintf(stderr, "Fila cheia!\n");
        exit(1);
    }
}

fpa_info fpa_remover_min(fpa * f)
{
    if (!fpa_isempty(*f)) {
        int i, menor = f->comeco;
        fpa_info aux;
        for (i = f->comeco + 1; i < f->final; i++) {
            if (f->itens[i % MAX] < f->itens[menor % MAX]) {
                menor = i;
            }
        }
        aux = f->itens[f->comeco % MAX];
        f->itens[f->comeco % MAX] = f->itens[menor % MAX];
        f->itens[menor % MAX] = aux;
        return f->itens[f->comeco++ % MAX];
    }
    else {
        fprintf(stderr, "Fila vazia!\n");
        exit(1);
    }
}

void fpa_print(fpa f)
{
    int i;
    printf("[ ");
    for (i = f.comeco; i < f.final; i++) {
        printf("%d,", f.itens[i % MAX]);
    }
    printf("\b ]\n");
}

void gerar_aleatorio(fpa * f){
    int x, i, a;
    x = (rand()%20)+1;
    for(i = 0; i < x; i++){
        a = rand()%9;
        fpa_inserir(f, a);
    }
}
