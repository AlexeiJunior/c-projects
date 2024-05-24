/* fila.h
 * Definição do TAD fpa (fila de prioridade ascendente) e
 * protótipo de suas operações */

#ifndef _FPA_H
#define _FPA_H
#include <stdbool.h>

#define MAX 20
typedef int fpa_info;
typedef struct {
    fpa_info itens[MAX];
    int comeco;
    int final;
} fpa;

/* função que inicializa a fila no estado vazio */
void fpa_init(fpa *);

/* função que verifica se a fila está vazia */
bool fpa_isempty(fpa);

/* função que verifica sse a fila está cheia */
bool fpa_isfull(fpa);

/* função que insere um novo elemento do final da fila */
void fpa_inserir(fpa *, fpa_info);

/* função remove e devolve o menor elemento da fila */
fpa_info fpa_remover_min(fpa *);

/* função que imprime o conteúdo da fila */
void fpa_print(fpa);

void gerar_aleatorio(fpa *);
#endif // _FPA_H
