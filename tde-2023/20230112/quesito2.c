#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int occorrenze(char sequenza[], char template[]) {
    int dimS = strlen(sequenza);
    int dimT = strlen(template);
    int i, j;
    int occ;
    int check;

    occ = 0;
    for(i = 0; i <= dimS - dimT; i++) {
        check = 1;

        for(j = 0; j < dimT && check; j++) {
            if(template[j] != '_' && sequenza[i + j] != template[j]) check = 0;
        }

        if(check) occ +=1;
    }

    return occ;
}

int main(void) {
    char sequenza[] = "ababcdAaabcadacd";
    char template[] = "a_a";

    int risultato = occorrenze(sequenza, template);
    printf("Occorrenze trovate: %d\n", risultato);

    return 0;
}
