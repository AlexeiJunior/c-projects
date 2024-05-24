#include <stdio.h>
#include "deque.h"

int main()
{
	deque d;
	deque_info val;
	int op;
	
	deque_init(&d);
	do {
		printf("\n\n\t\tDEQUE\n");
		printf("\t<1> Inserir pela esquerda\n");
		printf("\t<2> Inserir pela direita\n");
		printf("\t<3> Remover pela esquerda\n");
		printf("\t<4> Remover pela direita\n");
		printf("\t<5> Imprimir\n");
		printf("\t<0> Sair\n");
		printf("\tOpcao: ");
		scanf("%d", &op);
		switch (op) {
			case 1:
				printf("\n\tInserir pela esquerda:\n");
				printf("\tValor: ");
				scanf("%d", &val);
				deque_ins_esq(&d, val);
				break;
			case 2:
				printf("\n\tInserir pela direita:\n");
				printf("\tValor: ");
				scanf("%d", &val);
				deque_ins_dir(&d, val);
				break;
			case 3:
				printf("\n\tValor removido pela esquerda: %d\n", deque_rem_esq(&d));
				break;
			case 4:
				printf("\n\tValor removido pela direita: %d\n", deque_rem_dir(&d));
				break;
			case 5:
				printf("\n\tConteudo do deque: ");
				deque_print(d);
				break;
			case 0:
				break;
			default:
				printf("\n\tOpcao invalida!\n");
		}
	} while (op != 0);
	return 0;
}

