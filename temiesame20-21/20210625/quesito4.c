#include <stdio.h>
#include <string.h>

// Intestazione della funzione richiesta
int istypo(char dig[], char voc[]) {
    int i, j = 0;
    int lenDig = strlen(dig);
    int lenVoc = strlen(voc);

    if(lenDig < lenVoc) return 0;

    for(i = 0; i < lenDig; i++) {
        if(dig[i] == voc[j]) {
            j++;
        }

        if(j == lenVoc) return 1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    FILE* filename = NULL;
    char buffer[36];

    if(argc != 3) {
        return 1;
    }

    filename = fopen(argv[argc - 1], "r");
    if(filename == NULL) {
        return 1;
    }

    printf("%s\n", argv[argc - 2]);

    while(fgets(buffer, sizeof(buffer), filename) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Rimuove il newline

        if(istypo(argv[argc - 2], buffer)) printf("%s\n", buffer);
    }

    fclose(filename);

    return 0;
}