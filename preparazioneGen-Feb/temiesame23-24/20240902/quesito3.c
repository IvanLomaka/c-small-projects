#include <stdio.h>
#include <string.h>

void stampa(char ch, int val) {
    int i, j;
    int loop;

    int occorrenze[10] = {0};

    while(val > 0) {
        loop = val % 10;

        occorrenze[loop] = occorrenze[loop] + 1;

        val = val / 10;
    }

    for (i = 0; i < 10; i++) {
        if(occorrenze[i] != 0) {
            printf("%d:\t", i);
            for(j = 0; j < occorrenze[i]; j++) {
                printf("%c", ch);
            }

            printf("\n");
        }
    }
}

int main() {
    stampa('#', 203521);

    return 0;
}