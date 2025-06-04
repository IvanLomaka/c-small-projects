#include <stdio.h>
#include <math.h>

#define DIM 5

int narciso(int n, int x) {
    int sum = 0;
    int n1 = n;

    while(n1 > 0) {
        sum += pow(n1 % 10, x);
        n1 /= 10;
    }

    if(sum == n) {
        return 1;
    }

    return 0;
}

void trovanarcisisti(int numero[], int tipo[], int len, int x) {
    int i;

    for(i = 0; i < len; i++) {
        if(narciso(numero[i], x)) {
            tipo[i] = 1;
        } else {
            tipo[i] = 0;
        }
    }
}

int main(void) {
    int numero[DIM] = {153, 1634, 370, 123, 9474};
    int tipo[DIM];
    int i;
    int ordine = 3;

    trovanarcisisti(numero, tipo, DIM, ordine);

    printf("Numeri narcisistici di ordine %d:\n", ordine);
    for (i = 0; i < DIM; i++) {
        if (tipo[i] == 1) {
            printf("%d è narcisistico\n", numero[i]);
        } else {
            printf("%d NON è narcisistico\n", numero[i]);
        }
    }

    return 0;
}
