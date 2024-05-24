#include <stdio.h>
#include "lista.h"

int main()
{
    lista l, l2, l3;
    lst_gerar(&l, 20, 10);
    lst_imprimir(l);
    lst_insere_final(&l, 15);
    lst_insere_inicio(&l, 0);
    lst_imprimir(l);
    if (lst_ordenado(l)) {
        puts("A lista estah ordenada");
    }
    else {
        puts("A lista estah desordenada");
    }
    printf("%d elementos menores que 6 removidos da lista\n", lst_remover_menores(&l, 6));
    lst_imprimir(l);
    lst_gerar_ordenado(&l2, 15, 150);
    lst_gerar_ordenado(&l3, 10, 150);
    lst_imprimir(l2);
    lst_imprimir(l3);
    lst_concatena(l2, l3, &l);
    lst_imprimir(l);
    if (lst_ordenado(l)) {
        puts("Lista ordenada");
    }
    return 0;
}



int old_main()
{
    lista l;
    int k, op;
    lstInfo val;

    lst_init(&l);
    do {
        printf("\n\n\tLISTA LINEAR\n");
        printf("\t<1> Inserir\n");
        printf("\t<2> Remover\n");
        printf("\t<3> Acessar\n");
        printf("\t<4> Alterar\n");
        printf("\t<5> Imprimir\n");
        printf("\t<6> Procurar\n");
        printf("\t<0> Sair do programa\n");
        printf("\tOpcao: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            /*printf("\nNovo No\nPosicao: ");
            scanf("%d", &k); */
            printf("\nNovo no (ordenado)\n");
            printf("Valor: ");
            scanf("%d", &val);
            //if (lst_inserir(&l, k, val)) {
            if (lst_ins_ordenado(&l, val)) {
                printf("\nValor inserido com sucesso na lista\n");
            }
            else {
                printf("\nErro: posicao invalida ou lista cheia!\n");
            }
            break;
        case 2:
            printf("\nRemover um No\nPosicao: ");
            scanf("%d", &k);
            if (lst_remover(&l, k, &val)) {
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
            if (lst_alterar(&l, k, val)) {
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
            k = lst_procurar(l, val);
            if (k != -1) {
                printf("\n%d estah na posicao %d da lista\n", val, k);
            }
            else {
                printf("\nErro: %d nao estah contido na lista\n", val);
            }
            break;
        default:
            printf("\n\tOpcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}
