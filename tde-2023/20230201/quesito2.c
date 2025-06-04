#include <stdlib.h>
#include <stdio.h>

int sommaCifre(int num1, int num2) {
    int num3;
    int ordineDiGrandezza = 1;

    num3 = 0;
    while(num1 > 0 || num2 > 0) {
        if (num1 > 0) {
            num3 += (num1 % 10) * ordineDiGrandezza;
            num1 /= 10;
            ordineDiGrandezza *= 10;
        }

        if (num2 > 0) {
            num3 += (num2 % 10) * ordineDiGrandezza;
            num2 /= 10;
            ordineDiGrandezza *= 10;
        }
    }

    return num3;
}

int main(void) {
    int a = 121, b = 35365, risultato;

    risultato = sommaCifre(a, b);

    printf("Risultato: %d\n", risultato);

    return 0;
}
