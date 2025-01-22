#include <stdio.h>
#include <string.h>

int contaOccorrenze(char *sequenza, char *templete) {
    int count = 0;
    int sequenzaLen = strlen(sequenza);
    int templeteLen = strlen(templete);
    int i, found, j;

    for (i = 0; i < sequenzaLen - templeteLen; i++) {
        found = 1;

        for (j = 0; j < templeteLen; j++) {
            if (sequenza[i + j] != templete[j] && templete[j] != '_') {
                found = 0;
                break;
            }
        }

        if (found) {
            count ++;
        }
    }

    return count;
}

int main() {
    char sequenza[] = "ababcdAaabcadacd";
    char template[] = "a_a";

    int occorrenze = contaOccorrenze(sequenza, template);
    printf("Il template compare %d volte nella sequenza.\n", occorrenze);

    return 0;
}