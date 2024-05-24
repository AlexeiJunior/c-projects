/* abb.h
 * Definição do TAD que representa uma árvore binária de busca e protótipo de suas operações
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

/* função que inicializa a árvore */
void tree_init(arvbin *);

/* função que faz o percurso em-ordem */
void em_ordem(arvbin);

/* função que faz o percurso em pré-ordem */
void pre_ordem(arvbin);

/* função que faz o percurso em pós-ordem */
void pos_ordem(arvbin);

/* função que faz a inserção de um novo nó na árvore */
void tree_ins(arvbin *, tree_info);

/* função que faz uma busca na árvore */
arvbin tree_find(arvbin, tree_info);

/* função que retira e devolve o ponteiro para o nó que contém o
 * menor elemento da árvore */
arvbin getmin(arvbin *) ;

/* função que faz a remoção de um nó da árvore */
bool tree_rem(arvbin *, tree_info);

#endif // _ABB_H
