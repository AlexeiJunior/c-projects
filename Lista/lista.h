/* lista.h
 * Defini��o do TAD lista e prot�tipos de suas opera��es */

#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>

#define M 100  // tamanho do vetor
typedef int lstInfo; // tipo de dado da lista
typedef struct {
    lstInfo itens[M]; // itens da lista
    int n; // n�mero de n�s da lista
} lista;

/* fun��o que inicializa a lista no estado vazio */
void lst_init(lista *);

/* fun��o tenta acessar o k-�simo n� de uma lista e devolve
 * verdadeiro ou falso para indicar o sucesso ou falha da opera��o */
bool lst_acessar(lista, int, lstInfo *);

/* fun��o que tenta alterar o valor do k-�simo n� da lista e
 * devolve verdadeiro ou falso para indicar o sucesso ou falha da opera��o */
bool lst_alterar(lista *, int, lstInfo);

/* fun��o que tenta inserir um novo n� na k-�sima posi��o da lista e
 * devolve verdadeiro ou falso para indicar o sucesso ou falha da opera��o */
bool lst_inserir(lista *, int, lstInfo);

/* fun��o que tenta remover o n� da k-�sima posi��o da lista e devolve
 * verdadeiro ou falso para indicar o sucesso ou falha da opera��o */
bool lst_remover(lista *, int, lstInfo *);

/* fun��o que imprime a lista */
void lst_imprimir(lista);

/* fun��o que devolve a posi��o do n� que cont�m um valor, ou -1
 * caso o valor n�o esteja contido na lista */
int lst_procurar(lista, lstInfo);

/* fun��o que insere um novo n� na lista e a mant�m ordenada */
bool lst_ins_ordenado(lista *, lstInfo);

/* fun��o que concatena 2 listas ordenadas em uma 3� lista tamb�m
 * ordenada sem repeti��o */
bool lst_concatena(lista, lista, lista *);

/* fun��o que insere um novo n� no final da lista */
bool lst_insere_final(lista *, lstInfo);

/* fun��o que insere um novo n� no in�cio da lista */
bool lst_insere_inicio(lista *, lstInfo);

/* fun��o que gera aleatoriamente uma lista de n inteiros entre 1 e max */
bool lst_gerar(lista *, int, int);

/* fun��o que devolve verdadeiro se a lista est� ordenada, ou falso, caso contr�rio */
bool lst_ordenado(lista);

/* fun��o que remove todos os n�s com valores menores que um valor e devolve o
 * n�mero de remo��es */
int lst_remover_menores(lista *, lstInfo);

/* fun��o que gera aleatoriamente uma lista ordenada e sem repeti��o
 * de n inteiros entre 1 e max */
bool lst_gerar_ordenado(lista *, int, int);

#endif // _LISTA_H
