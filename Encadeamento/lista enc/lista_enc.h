/* lista_enc.h
 * Defini��o do TAD lista representado de forma encadeada e prot�tipos
 * das opera��es sobre esse tipo */

#ifndef _LISTA_ENC_H
#define _LISTA_ENC_H
#include <stdbool.h>

typedef int lst_info;
typedef struct lst_no * lst_ptr;
struct lst_no {
    lst_info dado;
    lst_ptr prox;
};

/* fun��o que inicializa a lista */
void lst_init(lst_ptr *);

/* fun��o que acessa o k-�simo n� da lista */
bool lst_acessar(lst_ptr, int, lst_info *);

/* fun��o para alterar o k-�simo n� da lista */
bool lst_alterar(lst_ptr, int, lst_info);

/* fun��o que insere um novo n� na k-�sima posi��o da lista */
bool lst_inserir(lst_ptr *, int, lst_info);

/* fun��o que remove e devolve o valor do k-�simo n� da lista */
bool lst_remover(lst_ptr *, int, lst_info *);

/* fun��o de devolve o n�mero de n�s da lista */
int lst_tamanho(lst_ptr);

/* fun��o que localiza o n� que cont�m um determinado valor */
lst_ptr lst_procurar(lst_ptr, lst_info);

/* fun��o que imprime a lista */
void lst_imprimir(lst_ptr);

#endif // _LISTA_ENC_H
