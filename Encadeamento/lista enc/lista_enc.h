/* lista_enc.h
 * Definição do TAD lista representado de forma encadeada e protótipos
 * das operações sobre esse tipo */

#ifndef _LISTA_ENC_H
#define _LISTA_ENC_H
#include <stdbool.h>

typedef int lst_info;
typedef struct lst_no * lst_ptr;
struct lst_no {
    lst_info dado;
    lst_ptr prox;
};

/* função que inicializa a lista */
void lst_init(lst_ptr *);

/* função que acessa o k-ésimo nó da lista */
bool lst_acessar(lst_ptr, int, lst_info *);

/* função para alterar o k-ésimo nó da lista */
bool lst_alterar(lst_ptr, int, lst_info);

/* função que insere um novo nó na k-ésima posição da lista */
bool lst_inserir(lst_ptr *, int, lst_info);

/* função que remove e devolve o valor do k-ésimo nó da lista */
bool lst_remover(lst_ptr *, int, lst_info *);

/* função de devolve o número de nós da lista */
int lst_tamanho(lst_ptr);

/* função que localiza o nó que contém um determinado valor */
lst_ptr lst_procurar(lst_ptr, lst_info);

/* função que imprime a lista */
void lst_imprimir(lst_ptr);

#endif // _LISTA_ENC_H
