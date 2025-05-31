#include <stdio.h>
#include <string.h>

void trova_stringa_succ(const char *si, char *sj, char *argv[], int start, int argc) {
    int len_si = strlen(si);

    // Assicuriamoci che la lunghezza di si sia almeno 2
    if (len_si < 2) {
        sj[0] = '\0';  // Imposta sj come stringa vuota se si non è valida
        return;
    }

    // Estrai le ultime due lettere di si
    char last_two[3];
    last_two[0] = si[len_si - 2];
    last_two[1] = si[len_si - 1];
    last_two[2] = '\0';

    // Cerca sj
    for (int i = start; i < argc; i++) {
        // Controlla se le prime due lettere di argv[i] corrispondono a last_two
        if (argv[i][0] == last_two[0] && argv[i][1] == last_two[1]) {
            strcpy(sj, argv[i]);
            return;
        }
    }

    // Se nessuna stringa valida è trovata, imposta sj come vuota
    sj[0] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Errore: Inserire almeno una stringa come argomento.\n");
        return 1;
    }

    for (int i = 1; i < argc - 1; i++) {
        char sj[256] = "";

        trova_stringa_succ(argv[i], sj, argv, i + 1, argc);

        if (sj[0] != '\0') {
            printf("%s %s\n", argv[i], sj);
        }
    }

    return 0;
}
