/* lista_enc_ord.h
 * Defini��o do TAD lista ordenada representado de forma encadeada e prot�tipo
 * de suas opera��es */

#ifndef _LISTA_ENC_ORD_H
#define _LISTA_ENC_ORD_H

#include <stdbool.h>

typedef int lst_info;
typedef struct lst_no * lst_ptr;
struct lst_no {
    lst_info dado;
    lst_ptr prox;
};

/* fun��o que inicializa a lista ordenada */
void lst_init(lst_ptr *);

/* fun��o que insere um novo n� na lista ordenada */
void lst_ins(lst_ptr *, lst_info);

/* fun��o que remove um n� da lista */
bool lst_rem(lst_ptr *, lst_info);

/* fun��o que procura um valor na lista */
lst_ptr lst_find(lst_ptr, lst_info);

/* fun��o que imprime a lista ordenada */
void lst_print(lst_ptr);

/* fun��o que destr�i a lista */
void lst_kill(lst_ptr *);

/* fun��o que devolve o n�mero de ocorr�ncias de um valo na lista ordenada */
int lst_occurs(lst_ptr, lst_info);

/* fun��o que devolce o tamanho da lista */
int lst_size(lst_ptr);

/* fun��o que remove todas as ocorr�ncias de um valor da lista e devolve
 * o n�mero de remo��es */
int lst_rem_all(lst_ptr *, lst_info);

/* fun��o que devolve uma lista ordenada gerada a partir da intercala��o
 * dos valores de duas listas */
lst_ptr lst_merge(lst_ptr, lst_ptr) ;

/* fun��o que verifica se duas listas ordenadas s�o iguais */
bool lst_equals(lst_ptr, lst_ptr);

#endif // _LISTA_ENC_ORD_H
