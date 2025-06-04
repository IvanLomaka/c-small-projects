#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* NON CONTROLLATO */

int diff(char nome1[], char nome2[]) {
    FILE *p1 = NULL;
    FILE *p2 = NULL;

    int c1, c2;

    p1 = fopen(nome1, "rb");
    if(p1 == NULL) return 0;
    p2 = fopen(nome2, "rb");
    if(p2 == NULL) {
        fclose(p1);
        return 0;
    }

    while((c1 = fgetc(p1)) != EOF) {
        c2 = fgetc(p2);
        if (c2 == EOF || c2 != c1) {
            fclose(p1);
            fclose(p2);
            return 0;
        }
    }

    if((c2 = fgetc(p2)) != EOF) {
        fclose(p1);
        fclose(p2);
        return 0;
    } else {
        fclose(p1);
        fclose(p2);
        return 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    if (diff(argv[1], argv[2]) == 0) {
        printf("I file sono identici.\n");
    } else {
        printf("I file sono diversi.\n");
    }

    return 0;
}