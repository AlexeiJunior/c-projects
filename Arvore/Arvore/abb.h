/* abb.h
 * Defini��o do TAD que representa uma �rvore bin�ria de busca e prot�tipo de suas opera��es
 */

#ifndef _ABB_H
#define _ABB_H

#include <stdbool.h>

typedef int tree_info;
typedef struct no_arvbin * arvbin;
struct no_arvbin {
    arvbin esq;
    tree_info dado;
    arvbin dir;
};

/* fun��o que inicializa a �rvore */
void tree_init(arvbin *);

/* fun��o que faz o percurso em-ordem */
void em_ordem(arvbin);

/* fun��o que faz o percurso em pr�-ordem */
void pre_ordem(arvbin);

/* fun��o que faz o percurso em p�s-ordem */
void pos_ordem(arvbin);

/* fun��o que faz a inser��o de um novo n� na �rvore */
void tree_ins(arvbin *, tree_info);

/* fun��o que faz uma busca na �rvore */
arvbin tree_find(arvbin, tree_info);

/* fun��o que retira e devolve o ponteiro para o n� que cont�m o
 * menor elemento da �rvore */
arvbin getmin(arvbin *) ;

/* fun��o que faz a remo��o de um n� da �rvore */
bool tree_rem(arvbin *, tree_info);

#endif // _ABB_H
