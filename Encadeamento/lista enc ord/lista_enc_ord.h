/* lista_enc_ord.h
 * Definição do TAD lista ordenada representado de forma encadeada e protótipo
 * de suas operações */

#ifndef _LISTA_ENC_ORD_H
#define _LISTA_ENC_ORD_H

#include <stdbool.h>

typedef int lst_info;
typedef struct lst_no * lst_ptr;
struct lst_no {
    lst_info dado;
    lst_ptr prox;
};

/* função que inicializa a lista ordenada */
void lst_init(lst_ptr *);

/* função que insere um novo nó na lista ordenada */
void lst_ins(lst_ptr *, lst_info);

/* função que remove um nó da lista */
bool lst_rem(lst_ptr *, lst_info);

/* função que procura um valor na lista */
lst_ptr lst_find(lst_ptr, lst_info);

/* função que imprime a lista ordenada */
void lst_print(lst_ptr);

/* função que destrói a lista */
void lst_kill(lst_ptr *);

/* função que devolve o número de ocorrências de um valo na lista ordenada */
int lst_occurs(lst_ptr, lst_info);

/* função que devolce o tamanho da lista */
int lst_size(lst_ptr);

/* função que remove todas as ocorrências de um valor da lista e devolve
 * o número de remoções */
int lst_rem_all(lst_ptr *, lst_info);

/* função que devolve uma lista ordenada gerada a partir da intercalação
 * dos valores de duas listas */
lst_ptr lst_merge(lst_ptr, lst_ptr) ;

/* função que verifica se duas listas ordenadas são iguais */
bool lst_equals(lst_ptr, lst_ptr);

#endif // _LISTA_ENC_ORD_H
