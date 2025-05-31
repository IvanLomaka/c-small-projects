#include <stdio.h>
#include <string.h>

// Sottoprogramma per trovare il carattere unico
char trovaCarattereUnico(const char *str) {
    int lunghezza = strlen(str);
    int meta = lunghezza / 2;

    // Array per tenere traccia delle occorrenze dei caratteri
    int occorrenze[256] = {0};

    // Conta le occorrenze dei caratteri nella prima metà
    for (int i = 0; i < meta; i++) {
        occorrenze[(unsigned char)str[i]]++;
    }

    // Sottrae le occorrenze dei caratteri nella seconda metà
    for (int i = meta; i < lunghezza; i++) {
        occorrenze[(unsigned char)str[i]]--;
    }

    // Cerca il carattere che ha un'occorrenza di +1 o -1
    for (int i = 0; i < 256; i++) {
        if (occorrenze[i] == 1 || occorrenze[i] == -1) {
            return (char)i;
        }
    }

    // Non dovrebbe mai arrivare qui secondo il problema dato
    return '\0';
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s string1 string2 ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        const char *str = argv[i];
        char risultato = trovaCarattereUnico(str);
        printf("Stringa: %s, Carattere unico: %c\n", str, risultato);
    }

    return 0;
}