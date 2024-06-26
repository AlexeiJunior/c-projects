/* avl.h
 * Defini��o do TAD para representar uma �rvore AVL e prot�tipo
 * de suas opera��es.
 *
 * Ciro C. Trindade
 * 28/Out/2015
 */

#ifndef _AVL_H
#define _AVL_H

#include <stdbool.h>

// Defini��o da estrutura de dados
typedef struct {
    char chave[21];
    int cont;
} avl_info;

typedef struct avl_no * avl_tree;

struct avl_no {
    avl_info dado;
    avl_tree esq;
    avl_tree dir;
    int bal; // balanceamento do n�
};

/*
 * Imprime a �rvore AVL t atrav�s de um percurso em ordem.
 */
void printTree(avl_tree t);


/*
 * Verifica se a palavra x j� ocorreu na �rvore AVL t; 
 * caso afirmativo, seu contador � incrementado; caso contr�rio, 
 * x � inserida em t e h sinaliza que houve um aumento da
 * altura de t.
 */
void avl_search(avl_tree * t, char * x, bool * h);


/* 
 * Faz uma rota��o para a direita na �rvore AVL t. 
 */
void rotacaoDir(avl_tree * t);


/*
 * Faz uma rota��o para a esquerda na �rvore AVL t.
 */
void rotacaoEsq(avl_tree *);

/*
 * Se a palavra x est� contida na �rvore AVL t, x �
 * removida de t, h sinaliza uma diminui��o da altura
 * de t e a fun��o devolve verdadeiro; caso contr�rio,
 * nada � feito e a fun��o devolve falso.
 */
bool delete(avl_tree * t, char * x, bool * h);


/*
 * Faz o balanceamento da �rvore AVL t ap�s uma remo��o 
 * em sua sub�rvore esquerda e sinaliza se houve uma 
 * dimui��o da altura dessa sub�rvore atrav�s de h.
 */
void balanceEsq(avl_tree * t, bool * h);


/*
 * Faz o balanceamento da �rvore AVL t ap�s uma remo��o 
 * em sua sub�rvore direita e sinaliza se houve uma 
 * dimui��o da altura dessa sub�rvore atrav�s de h.
 */
void balanceDir(avl_tree *, bool *);

/*
 * Devolve um ponteiro para o n� que cont�m o menor
 * valor na �rvore AVL t e sinaliza atrav�s de h se 
 * houve uma diminui��o da altura de t.
 */
avl_tree getMin(avl_tree * t, bool * h);

#endif
