/* deque.c
 * Implementação das operações realizadas sobre o TAD deque
 *
 * Ciro Cirne Trindade
 * 24/03/2015
 */

#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

void deque_init(deque * d) {
	d->esq = 0;
	d->dir = MAX - 1;
}

bool deque_isempty(deque d) {
	return d.esq == 0 && d.dir == MAX - 1;
}

bool deque_isfull(deque d) {
	return d.esq > d.dir;
}

void deque_ins_esq(deque * d, deque_info x) {
	if (!deque_isfull(*d)) {
		d->itens[d->esq++] = x;
	}
	else {
		fprintf(stderr, "Deque cheio!\n");
		exit(1);
	}
}

void deque_ins_dir(deque * d, deque_info x) {
	if (!deque_isfull(*d)) {
		d->itens[d->dir--] = x;
	}
	else {
		fprintf(stderr, "Deque cheio!\n");
		exit(1);
	}
}

deque_info deque_rem_esq(deque * d) {
	if (!deque_isempty(*d)) {
		if (d->esq > 0) { // há elementos inseridos pela esquerda
			return d->itens[--d->esq];
		}
		else { // remover o primeiro inserido pela direita
			deque_info x = d->itens[MAX - 1];
			int i;
			for (i = MAX - 2; i >= d->dir; i--) {
				d->itens[i+1] = d->itens[i];
			}
			d->dir++;
			return x;
		}
	}
	else {
		fprintf(stderr, "Deque vazio!\n");
		exit(1);
	}
}

deque_info deque_rem_dir(deque * d) {
	if (!deque_isempty(*d)) {
		if (d->dir < MAX - 1) { // há elementos inseridos pela direita
			return d->itens[++d->dir];
		}
		else { // remover o primeiro inserido pela esquerda
			deque_info x = d->itens[0];
			int i;
			for (i = 0; i < d->esq; i++) {
				d->itens[i] = d->itens[i + 1];
			}
			d->esq--;
			return x;
		}
	}
	else {
		fprintf(stderr, "Deque vazio!\n");
		exit(1);
	}
}

void deque_print(deque d) {
	int i;
	printf("[ ");
	for (i = d.esq - 1; i >= 0; i--) {
		printf("%d,", d.itens[i]);
	}
	for (i = MAX - 1; i > d.dir; i--) {
		printf("%d,", d.itens[i]);
	}
	printf("\b ]\n");
}
