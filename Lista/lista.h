/* lista.h
 * Definição do TAD lista e protótipos de suas operações */

#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>

#define M 100  // tamanho do vetor
typedef int lstInfo; // tipo de dado da lista
typedef struct {
    lstInfo itens[M]; // itens da lista
    int n; // número de nós da lista
} lista;

/* função que inicializa a lista no estado vazio */
void lst_init(lista *);

/* função tenta acessar o k-ésimo nó de uma lista e devolve
 * verdadeiro ou falso para indicar o sucesso ou falha da operação */
bool lst_acessar(lista, int, lstInfo *);

/* função que tenta alterar o valor do k-ésimo nó da lista e
 * devolve verdadeiro ou falso para indicar o sucesso ou falha da operação */
bool lst_alterar(lista *, int, lstInfo);

/* função que tenta inserir um novo nó na k-ésima posição da lista e
 * devolve verdadeiro ou falso para indicar o sucesso ou falha da operação */
bool lst_inserir(lista *, int, lstInfo);

/* função que tenta remover o nó da k-ésima posição da lista e devolve
 * verdadeiro ou falso para indicar o sucesso ou falha da operação */
bool lst_remover(lista *, int, lstInfo *);

/* função que imprime a lista */
void lst_imprimir(lista);

/* função que devolve a posição do nó que contém um valor, ou -1
 * caso o valor não esteja contido na lista */
int lst_procurar(lista, lstInfo);

/* função que insere um novo nó na lista e a mantém ordenada */
bool lst_ins_ordenado(lista *, lstInfo);

/* função que concatena 2 listas ordenadas em uma 3ª lista também
 * ordenada sem repetição */
bool lst_concatena(lista, lista, lista *);

/* função que insere um novo nó no final da lista */
bool lst_insere_final(lista *, lstInfo);

/* função que insere um novo nó no início da lista */
bool lst_insere_inicio(lista *, lstInfo);

/* função que gera aleatoriamente uma lista de n inteiros entre 1 e max */
bool lst_gerar(lista *, int, int);

/* função que devolve verdadeiro se a lista está ordenada, ou falso, caso contrário */
bool lst_ordenado(lista);

/* função que remove todos os nós com valores menores que um valor e devolve o
 * número de remoções */
int lst_remover_menores(lista *, lstInfo);

/* função que gera aleatoriamente uma lista ordenada e sem repetição
 * de n inteiros entre 1 e max */
bool lst_gerar_ordenado(lista *, int, int);

#endif // _LISTA_H
