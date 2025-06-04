#include <stdlib.h>
#include <stdio.h>

void disegna(int val, char c) {
    int ordineDiGrandezza = 1;
    int i;
    int disegnoRipetizioni;

    while((val / ordineDiGrandezza) >= 10) {
        ordineDiGrandezza *= 10;
    }

    while(val > 0) {
        disegnoRipetizioni = val / ordineDiGrandezza;

        for(i = 0; i < disegnoRipetizioni; i++) {
            printf("%c", c);
        }

        printf("\n");

        val %= ordineDiGrandezza;
        ordineDiGrandezza /= 10;
    }
}

int main(void) {
    disegna(2451, '*');

    return 0;
}
