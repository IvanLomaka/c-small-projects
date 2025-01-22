#include <stdio.h>
#include <ctype.h>
#include <string.h>

char diventaMinuscolo(char a) {
    if(a >='A' && a <= 'Z') {
        return a - 'A' + 'a';
    }

    return a;
}

int attacco(char seq[]) {
    int lunghezza = strlen(seq);
    int i;

    char carattereIniziale = '.';
    int checkCarattere = 1;

    for(i = 0; i < lunghezza; i++) {
        if((seq[i] >='a' && seq[i] <= 'z') || (seq[i] >='A' && seq[i] <= 'Z')) {
            if(checkCarattere) {
                seq[i] = diventaMinuscolo(seq[i]);
    
                if(carattereIniziale == '.') carattereIniziale = seq[i];

                if(carattereIniziale != seq[i]) {
                    return 0;
                }

                checkCarattere = 0;
            }
        } else {
            checkCarattere = 1;
        }
    }

    return 1;
}

int main() {
    char str[100];  // Define an array to store the input string

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);  // Read input from the user

    // Remove the newline character that fgets adds
    str[strcspn(str, "\n")] = '\0';  

    int risultato = attacco(str);
    
    if (risultato == 1) {
        printf("Tutti i vocaboli iniziano con lo stesso carattere.\n");
    } else {
        printf("I vocaboli non iniziano tutti con lo stesso carattere.\n");
    }
    
    return 0;
}
