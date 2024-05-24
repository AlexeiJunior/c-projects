#include <stdio.h>
#include "lista_enc_ord.h"


int main()
{
    lst_ptr l, n;
    int op;
    lst_info val;

    lst_init(&l);
    do {
        printf("\n\n\tLISTA ORDENADA ENCADEADA\n");
        printf("\t<1> Inserir\n");
        printf("\t<2> Remover\n");
        printf("\t<3> Imprimir\n");
        printf("\t<4> Procurar\n");
        printf("\t<5> Destruir a lista\n");
        printf("\t<0> Sair do programa\n");
        printf("\tOpcao: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            printf("\nNovo No\n");
            printf("Valor: ");
            scanf("%d", &val);
            lst_ins(&l, val);
            printf("\nValor inserido com sucesso na lista\n");
            break;
        case 2:
            printf("\nRemover um No\nValor: ");
            scanf("%d", &val);
            if (lst_rem(&l, val)) {
                printf("\n%d foi removido da lista\n", val);
            }
            else {
                printf("\nErro: valor nao localizado ou lista vazia\n");
            }
            break;
        case 3:
            printf("\nConteudo do lista: ");
            lst_print(l);
            break;
        case 4:
            printf("\nProcurar um valor na lista\nValor: ");
            scanf("%d", &val);
            n = lst_find(l, val);
            if (n != NULL) {
                printf("\n%d estah contido na lista\n", val);
            }
            else {
                printf("\nErro: %d nao estah contido na lista\n", val);
            }
            break;
        case 5:
            lst_kill(&l);
            printf("\nA lista foi destruida!\n");
            break;
        default:
            printf("\n\tOpcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}
