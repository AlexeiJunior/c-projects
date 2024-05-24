/* lista.c
 * Implementação das operações realizadas sobre o TAD lista */

#include "lista.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void lst_init(lista * l)
{
    l->n = 0;
}

bool lst_acessar(lista l, int k, lstInfo * val)
{
    if (k >= 0 && k < l.n) {
        *val = l.itens[k];
        return true;
    }
    return false;
}

bool lst_alterar(lista * l, int k, lstInfo val)
{
    if (k >= 0 && k < l->n) {
        l->itens[k] = val;
        return true;
    }
    return false;
}

bool lst_inserir(lista * l, int k, lstInfo val)
{
    if (l->n < M && k >= 0 && k <= l->n) {
        int i;
        for (i = l->n - 1; i >= k; i--) {
            l->itens[i + 1] = l->itens[i];
        }
        l->itens[k] = val;
        l->n++;
        return true;
    }
    return false;
}

bool lst_remover(lista * l, int k, lstInfo * val)
{
    if (k >= 0 && k < l->n) {
        int i;
        *val = l->itens[k];
        for (i = k + 1; i < l->n; i++) {
            l->itens[i - 1] = l->itens[i];
        }
        l->n--;
        return true;
    }
    return false;
}

void lst_imprimir(lista l)
{
    int i;
    printf("[ ");
    for (i = 0; i < l.n; i++) {
        printf("%d,", l.itens[i]);
    }
    printf("\b ]\n");
}

int lst_procurar(lista l, lstInfo val)
{
    int i;
    for (i = 0; i < l.n; i++) {
        if (l.itens[i] == val) {
            return i;
        }
    }
    return -1;
}

bool lst_ins_ordenado(lista * l, lstInfo val)
{
    if (l->n < M) {
        int k, i;

        for (k = 0; k < l->n && l->itens[k] < val; k++);

        for (i = l->n - 1; i >= k; i--) {
            l->itens[i + 1] = l->itens[i];
        }
        l->itens[k] = val;
        l->n++;
        return true;
    }
    return false;
}

bool lst_concatena(lista lst1, lista lst2, lista * lst3)
{
    int i;
    lstInfo val;
    /* copia a lst1 para lst3 */
    for (i = 0; i < lst1.n; i++) {
        lst3->itens[i] = lst1.itens[i];
    }
    lst3->n = lst1.n;
    /* insere os elementos de lst2 em lst3 em ordem */
    for (i = 0; i < lst2.n; i++) {
        val = lst2.itens[i];
        if (lst_procurar(*lst3, val) == -1) {
            if (!lst_ins_ordenado(lst3, val)) {
                return false;
            }
        }
    }
    return true;
}

bool lst_insere_final(lista * l, lstInfo val)
{
    if (l->n < M) {
        l->itens[l->n] = val;
        l->n++;
        return true;
    }
    return false;
}

bool lst_insere_inicio(lista * l, lstInfo val)
{
    if (l->n < M) {
        int i;
        for (i = l->n - 1; i >= 0; i--) {
            l->itens[i+1] = l->itens[i];
        }
        l->itens[0] = val;
        l->n++;
        return true;
    }
    return false;
}

bool lst_gerar(lista * l, int n, int max)
{
    if (n < M) {
        int i;
        srand(time(NULL));
        for (i = 0; i < n; i++) {
            l->itens[i] = rand() % max + 1;
        }
        l->n = n;
        return true;
    }
    return false;
}

bool lst_ordenado(lista l)
{
    int i;
    for (i = 1; i < l.n; i++) {
        if (l.itens[i] < l.itens[i - 1]) {
            return false;
        }
    }
    return true;
}

int lst_remover_menores(lista * l, lstInfo val)
{
    int i, j, cont = 0;
    for (i = 0; i < l->n; i++) {
        if (l->itens[i] < val) {
            for (j = i; j < l->n - 1; j++) {
                l->itens[j] = l->itens[j + 1];
            }
            l->n--;
            cont++;
            i--;
        }
    }
    return cont;
}

bool lst_gerar_ordenado(lista * l, int n, int max)
{
    if (n < M) {
        int i, val;
        srand(time(NULL));
        lst_init(l);
        for (i = 0; i < n; i++) {
            val = rand() % max + 1;
            if (lst_procurar(*l, val) == -1) {
                lst_ins_ordenado(l, val);
            }
        }
        return true;
    }
    return false;
}
