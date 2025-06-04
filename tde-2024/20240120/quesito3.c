#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MIN_LEN 6

int verifica(int n) {
    int len = 0;
    int prevCheck;
    int prev;
    int current;
    int crescenteCheck;

    current = n % 10;
    n /= 10;
    len++;

    prevCheck = 0;
    crescenteCheck = 1;
    while(n > 0 && crescenteCheck) {
        prev = current;
        current = n % 10;
        n /= 10;
        len++;
        if(prev == current) prevCheck = 1;
        if(prev < current) crescenteCheck = 0;
    }

    if(prevCheck && crescenteCheck && len >= MIN_LEN) return 1;

    return 0;
}

int main(int argc, char *argv[]) {
    int numero = 223450;

    printf("%d\n", verifica(numero));
}
