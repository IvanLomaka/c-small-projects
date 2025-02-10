#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *filesorgente;
    char buffer[41];
    char rowBuffer[201];
    char currentChar;
    int i;

    int numRighe = 0;

    int currentCaratteri = 0;

    int minCaratteri = 202;
    int maxCaratteri = 0;
    int numFrasi = 0;

    scanf("%40s", buffer);

    filesorgente = fopen(buffer, "r");
    if(filesorgente == NULL) return 1;

    while(fgets(rowBuffer, sizeof(rowBuffer), filesorgente) != NULL) {
        currentCaratteri = 0;

        for(i = 0; rowBuffer[i] != '\0'; i++) {
            if(rowBuffer[i] == '.') {
                numFrasi ++;
            }
            if(rowBuffer != ' ')currentCaratteri ++;
            
        }

        if(currentCaratteri > maxCaratteri) {
            maxCaratteri = currentCaratteri;
        }

        if(currentCaratteri < minCaratteri) {
            minCaratteri = currentCaratteri;
        }

        numRighe ++;
    }

    printf("Numero di righe: %d\n", numRighe);
    printf("Numero massimo di caratteri in una riga: %d\n", maxCaratteri);
    printf("Numero minimo di caratteri in una riga: %d\n", minCaratteri);
    printf("Numero di frasi: %d\n", numFrasi);

    fclose(filesorgente);
    
    return 0;
}