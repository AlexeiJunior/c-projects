/* fila.h
 * Defini��o do TAD fpa (fila de prioridade ascendente) e
 * prot�tipo de suas opera��es */

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

/* fun��o que inicializa a fila no estado vazio */
void fpa_init(fpa *);

/* fun��o que verifica se a fila est� vazia */
bool fpa_isempty(fpa);

/* fun��o que verifica sse a fila est� cheia */
bool fpa_isfull(fpa);

/* fun��o que insere um novo elemento do final da fila */
void fpa_inserir(fpa *, fpa_info);

/* fun��o remove e devolve o menor elemento da fila */
fpa_info fpa_remover_min(fpa *);

/* fun��o que imprime o conte�do da fila */
void fpa_print(fpa);

void gerar_aleatorio(fpa *);
#endif // _FPA_H
