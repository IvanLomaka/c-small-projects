#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    FILE *nomeSorgente;
    FILE *nomeDestinazione;
    char buffer[81];
    int i = 0;
    int scritto = 0;

    if(argc < 3) {
        return 1;
    }

    nomeSorgente = fopen(argv[1], "r");
    if (nomeSorgente == NULL) {
        perror("Error opening source file");
        return 1;
    }

    nomeDestinazione = fopen(argv[2], "w");
    if (nomeDestinazione == NULL) {
        perror("Error opening source file");
        return 1;
    }
    
    while(fgets(buffer, 81, nomeSorgente) != NULL) {
        scritto = 0;

        for(int i = 0; buffer[i] != '\0'; i++) {
            if(!isspace((unsigned char)buffer[i])) {
                scritto = 1;
            }
        }

        if(scritto) {
            fputs(buffer, nomeDestinazione);
        }
    }

    // Chiude i file dopo l'uso
    fclose(nomeSorgente);
    fclose(nomeDestinazione);

    printf("Operazione completata con successo.\n");

    return 0;
}