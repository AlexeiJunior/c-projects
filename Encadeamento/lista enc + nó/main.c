#include <stdio.h>
#include "lista_enc.h"


int main()
{
    lst_ptr l, n;
    int k, op;
    lst_info val;

    lst_init(&l);
    do {
        printf("\n\n\tLISTA LINEAR\n");
        printf("\t<1> Inserir\n");
        printf("\t<2> Remover\n");
        printf("\t<3> Acessar\n");
        printf("\t<4> Alterar\n");
        printf("\t<5> Imprimir\n");
        printf("\t<6> Procurar\n");
        printf("\t<7> Tamanho da lista\n");
        printf("\t<0> Sair do programa\n");
        printf("\tOpcao: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            printf("\nNovo No\nPosicao: ");
            scanf("%d", &k);
            printf("Valor: ");
            scanf("%d", &val);
            if (lst_inserir(l, k, val)) {
                printf("\nValor inserido com sucesso na lista\n");
            }
            else {
                printf("\nErro: posicao invalida ou lista cheia!\n");
            }
            break;
        case 2:
            printf("\nRemover um No\nPosicao: ");
            scanf("%d", &k);
            if (lst_remover(l, k, &val)) {
                printf("\n%d foi removido da lista\n", val);
            }
            else {
                printf("\nErro: posicao invalida ou lista vazia\n");
            }
            break;
        case 3:
            printf("\nAcessar um no\nPosicao: ");
            scanf("%d", &k);
            if (lst_acessar(l, k, &val)) {
                printf("\nValor do no na posicao %d: %d\n", k, val);
            }
            else {
                printf("\nErro: posicao invalida\n");
            }
            break;
        case 4:
            printf("\nAlterar um no\nPosicao: ");
            scanf("%d", &k);
            printf("Valor: ");
            scanf("%d", &val);
            if (lst_alterar(l, k, val)) {
                printf("\nO no da posicao %d foi alterado para %d\n", k, val);
            }
            else {
                printf("\nErro: posicao invalida\n");
            }
            break;
        case 5:
            printf("\nConteudo do lista: ");
            lst_imprimir(l);
            break;
        case 6:
            printf("\nProcurar um valor na lista\nValor: ");
            scanf("%d", &val);
            n = lst_procurar(l, val);
            if (n != NULL) {
                printf("\n%d estah contido na lista\n", val);
            }
            else {
                printf("\nErro: %d nao estah contido na lista\n", val);
            }
            break;
        case 7:
            printf("\nNumero de nos da lista: %d\n", lst_tamanho(l));
            break;
        default:
            printf("\n\tOpcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}
