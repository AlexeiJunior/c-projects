#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#define TAM 500000

int main(){
    int vet[TAM], i;
    bool debug = false;
    bool aleatorio = false;

    srand(time(NULL));

    for (i = 0; i < TAM; i++)
    {
        if(!aleatorio){
            vet[i] = i;
        }
        else{
            vet[i] = rand()%1000;
        }
        if (debug)
            printf("%d ", vet[i]);
    }

    //insercaoDireta(vet, TAM);
    //selecaoDireta(vet, TAM);
    //bubbleSort(vet, TAM);
    //shellSort(vet, TAM, 6);
    //heapSort(vet, TAM);
    //quickSort(vet, TAM, 6);
    //mergeSort(vet, TAM, 6);

    if (debug)
    {
        printf("\n\n-----------------------------\n\n");
        for (i = 0; i < TAM; i++)
        {
            printf("%d ", vet[i]);
        }
    }

    return 0;
}

/*

    Testes de desempenho

    - Inserção direta
        Vetor ordenado: 0.010s
        Vetor aleatório: 6.740s
    - Seleção direta
        Vetor ordenado: 12.400s
        Vetor aleatorio: 12.400s
    - BubbleSort
        Vetor ordenado: 10.500s
        Vetor aleatorio: 28.000s
    - ShellSort
        Vetor ordenado: 0.013s
        Vetor aleatorio: 0.170s
*/



/*----------------------------------------------------------------------------------------*/
/*                INSERCAO                                                                */
/*----------------------------------------------------------------------------------------*/
void insercaoDireta(int a[], int n)
{
    int i, // Passos do algoritmo
        j, // Indice para a sequencia destino
        x; // Primeiro elemento da sequencia fonte

    for(i = 1; i < n; i++)
    {
        x = a[i];
        j = i-1;
        while(j >= 0 && a[j] > x)
        {
            a[j+1] = a[j--]; // Desloca o elemento para a direita
        }
        a[j+1] = x; // Insere o elemento na posição correta
    }
}
/*----------------------------------------------------------------------------------------*/
/*                SELECAO                                                                 */
/*----------------------------------------------------------------------------------------*/
void selecaoDireta(int a[], int n)
{
    int i; // Passos do algoritmo
    int j; // Índice do vetor
    int k; // Índice do menor elemento da sequencia
    int menor; // Menor elemento da sequencia

    for (i = 0; i < n-1; i++)
    {
        k = i;
        for (j = i+1; j < n; j++) // procura o menor elemento da sequencia
        {
            if(a[j] < a[k])
            {
                k = j;
            }
        }
        // troca o menor elemento com o primeiro da sequencia
        menor = a[k];
        a[k] = a[i];
        a[i] = menor;
    }
}
/*----------------------------------------------------------------------------------------*/
/*                BubbleSort                                                              */
/*----------------------------------------------------------------------------------------*/
void bubbleSort(int a[], int n)
{
    int i; // Passos do algoritmo de ordenação
    int j; // Ìndice do vetor
    int aux; // Variavel auxiliar para a troca

    for (i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-1-i; j++)
        {
            if(a[j] > a[j+1]) //Elemento da esquerda maior que o da direita?
            {
                aux = a[j]; //Troca a posição deles
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
    }
}

void bubbleSort2(int a[], int n)
{
    int i = 0; // Passos do algoritmo de ordenação
    int j;
    int aux; // Variável auxiliar para a permutação de elementos
    bool trocou; // Indica se houve permutação em um passo
    do
    {
        trocou = false;
        for(j = 0; j < n-1-i; j++)
        {
            if(a[j] > a[j+1]) //Elemento da esquerda maior que o da direita?
            {
                aux = a[j];
                a[j] = a[j+1]; // Troca a posição destes elementos
                a[j+1] = aux;
                trocou = true; // Sinaliza a troca

            }
        }
    }while(trocou && ++i < n - 1);
}
/*----------------------------------------------------------------------------------------*/
/*                ShellSort                                                               */
/*----------------------------------------------------------------------------------------*/
void insercaoShell(int a[], int n, int f, int h)
{
    int i, // Passos do algoritmo
        j, // Indice do vetor
        x; // Elemento a ser inserido
    for (i = f + h; i < n; i += h)
    {
        x = a[i];
        j = i - h;
        while (j >= f && a[j] > x)
        {
            a[j + h] = a[j];
            j -= h;
        }
        a[j + h] = x;
    }
}

void shellSort(int a[], int n, int k) // qisso int k? the h=4?
{
    int i, // Numero de segmentos
        h; // Tamanho do incremento
    do
    {
        h = pow(2,k) - 1;
        for (i = 0; i < h; i++)
        {
            insercaoShell(a, n, i, h);
        }
        k--;
    }
    while (k >= 1);
}
/*----------------------------------------------------------------------------------------*/
/*                HeapSort                                                                */
/*----------------------------------------------------------------------------------------*/
void heap(int a[], int e, int d){
    int i = e, j = 2*e+1; // índices do heap
    int x = a[e]; // novo elemento
    if(j < d && a[j+1] > a[j]) j++;
    while(j <= d && a[j] > x){
        a[i] = a[j];
        i = j;
        j = 2 * j + 1;
        if(j < d && a[j+1] > a[j]) j++;
    }
    a[i] = x;
}


void heapSort(int a[], int n){
    int e = (n/2), d = n-1, x;
    while(e > 0){ // montagem do heap inicial
        e--;
        heap(a,e,d);
    }
    while(d > 0){ // n­1 passos de escorregamento
        x = a[0];
        a[0] = a[d];
        a[d] = x;
        d--;
        heap(a,0,d);
    }
}
/*----------------------------------------------------------------------------------------*/
/*                QuickSort                                                               */
/*----------------------------------------------------------------------------------------*/
void quickSort(int a[], int e, int d){
    int i = e; // Índice esquerdo
    int j = d; // Índice direito
    int x; // Elemento mediano do vetor
    int aux; // Variável auxiliar para troca
    x = a[(i+j) / 2];
    do{
        while (a[i] < x) i++;
        while (x < a[j]) j--;
        if(i <= j){
            aux = a[i];
            a[i++] = a[j];
            a[j--] = aux;
        }
    }while(i <= j);
    if(e < j) quickSort(a,e,j);
    if(i < d) quickSort(a,i,d);
}
/*----------------------------------------------------------------------------------------*/
/*                MergeSort                                                               */
/*----------------------------------------------------------------------------------------*/
void intercala(int a[], int p, int q, int r){
    int i = p, j = q, k = 0;
    int * w;
    w = malloc((r - p) * sizeof(int));
    while(i < 1 && j < r){
        if(a[i] <= a[j]) w[k++] = a[i++];
        else w[k++] = a[j++];
    }
    while(i < q) w[k++] = a[i++];
    while(j < r) w[k++] = a[j++];
    for(i = p; i < r; i++)
        a[i] = w[i - p];
    free(w);
}

void mergeSort(int a[], int p, int r){
    if(p < r - 1){
        int q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q, r);
        intercala(a, p, q, r);
    }
}
/*----------------------------------------------------------------------------------------*/