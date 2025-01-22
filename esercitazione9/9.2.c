// 9.2 Scrivi un programma in C che scambi i valori di due numeri interi utiliz-
// zando i puntatori.

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10;
    int b = 5;

    swap(&a, &b);

    printf("a: %d, b: %d\n", a, b);

    return 0;
}