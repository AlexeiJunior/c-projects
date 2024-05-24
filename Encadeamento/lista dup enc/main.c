#include <stdio.h>
#include "dlst.h"

int main()
{
    dlst_ptr l;
    int op;
    dlst_info x;

    dlst_init(&l);
    do {
        printf("\n\tLISTA ORDENADA DUPLAMENTE ENCADEADA CIRCULAR COM NO CABECA\n");
        printf("\t<1> Inserir\n");
        printf("\t<2> Remover\n");
        printf("\t<3> Imprimir em ordem crescente\n");
        printf("\t<4> Imprimir em ordem decrescente\n");
        printf("\t<5> Remover o ultimo\n");
        printf("\t<6> Inverter a lista\n");
        printf("\t<0> Sair\n");
        printf("\tOpcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: printf("\n\tValor para inserir: ");
                    scanf("%d", &x);
                    dlst_inserir(l, x);
                    break;
            case 2: printf("Valor para remover: ");
                    scanf("%d", &x);
                    if (dlst_remover(l, x)) {
                        printf("\tRemocao realizada com sucesso!\n");
                    }
                    else {
                        printf("\t%d nao estah contido na lista!\n", x);
                    }
                    break;
            case 3: dlst_print_cresc(l);
                    break;
            case 4: dlst_printf_dec(l);
                    break;
            case 5: printf("\n\tUltimo: %d\n", dlst_delete_last(l));
                    break;
            case 6: dlst_reverse(l);
                    break;
            case 0: break;
            default: printf("\n\tOpcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}
