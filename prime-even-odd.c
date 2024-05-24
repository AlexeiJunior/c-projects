#include <stdio.h>

void printPrime(int x) {
    if (x < 2) return;
    for (int i = 2; i*i <= x; i++) {
        if (x % i == 0) return printPrime(x-1);
    }
    printf("%d ", x);
    return printPrime(x-1);
}

void printEven(int x) {
    if (x < 0) return;
    if (x % 2 == 0) printf("%d ", x);
    return printEven(x-1);
}

void printOdd(int x) {
    if (x == 0) return;
    if (x % 2 != 0) printf("%d ", x);
    return printOdd(x-1);
}

int main(){
    int x;
    
    printf("ENTER A NUMBER: ");
    scanf("%d", &x);
    
    printf("PRIME: ");
    printPrime(x);
    printf("\nEVEN: ");
    printEven(x);
    printf("\nODD: ");
    printOdd(x);
    
    return 0;
}
