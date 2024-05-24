#include <stdio.h>
#include "fila.h"

int main()
{
    fila f;
    queue_info var;
    int op;
    queue_init(&f);
    do {
        printf("\n\tFILA\n");
        printf("\t<1> Inserir\n");
        printf("\t<2> Remover\n");
        printf("\t<3> Imprimir\n");
        printf("\t<4> Fura fila\n");
        printf("\t<5> Procurar\n");
        printf("\t<0> Sair do programa\n");
        printf("\tOpcao: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            printf("\n\n\tInserir\n\tValor: ");
            scanf("%d", &var);
            enqueue(&f, var);
            break;
        case 2:
            printf("\n\n\tRemover\n\tValor: %d\n", dequeue(&f));
            break;
        case 3:
            printf("\n\n\tConteudo da fila: ");
            queue_print(f);
            break;
        case 4:
            printf("\n\n\tFura Fila\n\tValor: ");
            scanf("%d", &var);
            queue_fura_fila(&f, var);
            break;
        case 5:
            printf("\n\n\tProcurar\n\tValor: ");
            scanf("%d", &var);
            if(queueContem(f, var)){
                printf("\tEste valor esta contido na fila!\n");
            }
            else{
                printf("\tEste valor NAO esta contido na fila!\n");
            }
        case 0:
            break;
        default:
            printf("\n\tOpcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}
