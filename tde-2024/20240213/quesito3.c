#include <stdlib.h>
#include <stdio.h>

int interoInOtto(int n) {
    if(n >= 0 && n < 7) return n + 1;

    return 0;
}

int prossimointero(int n) {
    int num;
    int i;
    int ordineGrandezza = 1;

    num = 0;
    while(n > 0) {
        i = interoInOtto(n % 10);

        n /= 10;

        num += i * ordineGrandezza;

        ordineGrandezza *= 10;
    }

    return num;
}

int main(int argc, char *argv[]) {
    int num = 7267;

    printf("%d\n", prossimointero(num));

    return 0;
}
