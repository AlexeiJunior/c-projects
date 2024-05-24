/* avl.c
 * Implementação das operações realizadas sobre o TAD que r
 * representa uma árvore AVL.
 *
 * Ciro C. Trindade
 * 28/Out/2015
 */
 
#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTree(avl_tree t) {
    if(t != NULL) {
        printTree(t->esq);
        printf("%40s: %d\n", t->dado.chave, t->dado.cont);
        printTree(t->dir);
    }
}

void avl_search(avl_tree * t, char * x, bool * h) {
    if (*t == NULL) {
        if ((*t = (avl_tree) malloc(sizeof(struct avl_no))) == NULL) {
            fprintf(stderr,"Erro de alocação de memória!\n");
            exit(1);
        }
        *h = true;
        strcpy((*t)->dado.chave,x);
        (*t)->dado.cont = 1;
        (*t)->esq = (*t)->dir = NULL;
        (*t)->bal = 0;
    }
    else if (strcasecmp(x,(*t)->dado.chave) < 0) { // Inserir a esquerda
        avl_search(&(*t)->esq, x, h);
        if (*h) { // O ramo esquerdo cresceu
            switch ((*t)->bal) {
                case 1: (*t)->bal = 0;
                        *h = false;
                        break;
                case 0: (*t)->bal = -1;
                        break;
                case -1:
                    // Rebalanceamento
                    if ((*t)->esq->bal == -1) { //Rotação simples p/ direita
                        rotacaoDir(t);
                        (*t)->dir->bal = 0; //Ajusta o fator de balanceamento
                    }
                    else { // Rotação dupla para direita
                        rotacaoEsq(&(*t)->esq);
                        rotacaoDir(t);
                        // Ajusta o fator de balanceamento
                        if ((*t)->bal == -1) (*t)->dir->bal = +1;
                        else (*t)->dir->bal = 0;
                        if ((*t)->bal == +1) (*t)->esq->bal = -1;
                        else (*t)->esq->bal = 0;
                    }
                    *h = false;
                    (*t)->bal = 0;
                    break;
            } // fim do switch
        }
    } // fim do if
    else if (strcasecmp(x,(*t)->dado.chave) > 0) { // Inserir a direita
        avl_search(&(*t)->dir, x, h);
        if (*h) { // O ramo direito cresceu
            switch ((*t)->bal) {
                case -1: (*t)->bal = 0;
                         *h = false;
                         break;
                case 0 : (*t)->bal = +1;
                         break;
                case +1: // Rebalanceamento
                    if ((*t)->dir->bal == +1) { // Rotação simples p/ esquerda
                        rotacaoEsq(t);
                        // Ajusta o fator de balanceamento
                        (*t)->esq->bal = 0;
                    }
                    else { // Rotação dupla para esquerda
                        rotacaoDir(&(*t)->dir);
                        rotacaoEsq(t);
                        // Ajusta o fator de balanceamento
                        if ((*t)->bal == +1) (*t)->esq->bal = -1;
                        else (*t)->esq->bal = 0;
                        if ((*t)->bal == -1) (*t)->dir->bal = +1;
                        else (*t)->dir->bal = 0;
                    } // fim do else
                    *h = false;
                    (*t)->bal = 0;
                    break;
            } // fim do switch
        }
    } // fim do if
    else // a chave já está na árvore
        (*t)->dado.cont++;
} // fim de avl_search

// Rotaçao para a esquerda
void rotacaoEsq(avl_tree * t) {
    avl_tree p;
    p = (*t)->dir;
    (*t)->dir = p->esq;
    p->esq = *t;
    *t = p;
}

// Rotação para a direita
void rotacaoDir(avl_tree * t) {
    avl_tree p;
    p = (*t)->esq;
    (*t)->esq = p->dir;
    p->dir = *t;
    *t = p;
}


bool delete(avl_tree * t, char * x, bool * h) {
    avl_tree p;
    bool result;
    if (*t == NULL) // A chave não se encontra na árvore
        return false;
    else if (strcasecmp(x,(*t)->dado.chave) == 0) { // a chave está neste nó
        p = *t;
        if ((*t)->esq == NULL) { // nó folha ou somente com subárvore direita
            *t = p->dir;
            *h = true;
        }
        else if ((*t)->dir == NULL) { // nó com uma única subárvore esquerda
            *t = p->esq;
            *h = true;
        }
        else { // nó com duas subávores
            p = getMin(&(*t)->dir, h);
            (*t)->dado = p->dado;
            if(*h) balanceDir(t, h);
        }
        free(p);
        return true;
    }
    else if (strcasecmp(x,(*t)->dado.chave) < 0) {
        result = delete(&(*t)->esq, x, h);
        if (*h) balanceEsq(t, h);
        return result;
    }
    else {
        result = delete(&(*t)->dir, x, h);
        if (*h) balanceDir(t, h);
        return result;
    }
} // fim do delete

void balanceDir(avl_tree * t, bool * h) {
    avl_tree p1, p2;
    int b1, b2;

    switch ((*t)->bal) {
        case 1: (*t)->bal = 0;
                break;
        case 0: (*t)->bal = -1;
                *h = false;
                break;
        case -1: // rebalanceamento
                p1 = (*t)->esq;
                b1 = p1->bal;
                if (b1 <= 0) { // rotação simples
                    (*t)->esq = p1->dir;
                    p1->dir = *t;
                    if (b1 == 0) {
                        (*t)->bal = -1;
                        p1->bal = 1;
                        *h = false;
                    }
                    else {
                        (*t)->bal = 0;
                        p1->bal = 0;
                    }
                    *t = p1;
                }
                else { // rotação dupla
                    p2 = p1->dir;
                    b2 = p2->bal;
                    p1->dir = p2->esq;
                    p2->esq = p1;
                    p1->esq = p2->dir;
                    p2->dir = *t;
                    if(b2 == -1) (*t)->bal = 1;
                    else (*t)->bal = 0;
                    if(b2 == 1) p1->bal = -1;
                    else p1->bal = 0;
                    *t = p2;
                    p2->bal = 0;
                }
    } // fim do switch
}

void balanceEsq(avl_tree * t, bool * h) {
    avl_tree p1, p2;
    int b1, b2;

    switch ((*t)->bal) {
        case -1: (*t)->bal = 0;
                 break;
        case 0: (*t)->bal = 1;
                *h = false;
                break;
        case 1: // rebalanceamento
                p1 = (*t)->dir;
                b1 = p1->bal;
                if (b1 >= 0) { // rotação simples
                    (*t)->dir = p1->esq;
                    p1->esq = *t;
                    if (b1 == 0) {
                        (*t)->bal = 1;
                        p1->bal = -1;
                        *h = false;
                    }
                    else {
                        (*t)->bal = 0;
                        p1->bal = 0;
                    }
                    *t = p1;
                }
                else { // rotação dupla
                    p2 = p1->esq;
                    b2 = p2->bal;
                    p1->esq = p2->dir;
                    p2->dir = p1;
                    p1->dir = p2->esq;
                    p2->esq = *t;
                    if (b2 == 1) (*t)->bal = -1;
                    else (*t)->bal = 0;
                    if (b2 == -1) p1->bal = 1;
                    else p1->bal = 0;
                    *t = p2;
                    p2->bal = 0;
                }
    } // fim do switch
}


avl_tree getMin(avl_tree * t, bool * h) {
    avl_tree q;
    if ((*t)->esq != NULL) {
        q = getMin(&((*t)->esq),h);
        if (*h) balanceEsq(t, h);
        return q;
    }
    else {
        *h = true;
        q = *t;
        *t = (*t)->dir;
        return q;
    }
}
