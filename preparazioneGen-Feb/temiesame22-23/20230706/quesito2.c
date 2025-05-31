#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Dichiarazione del sottoprogramma che modifica la stringa
void capitalizzaVocaboli(char* str) {
    int len = strlen(str);
    int i;
    int inizioParola = 1;

    for (i = 0; i < len; i++) {
        if (inizioParola) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 'a' + 'A'; // Convert to uppercase
                inizioParola = 0;
            } else {
                if(str[i] >= 'A' && str[i] <= 'Z') {
                    inizioParola = 0;
                }
            }
        } else {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] - 'A' + 'a'; // Convert to lowercase
            } 
        }
        if (str[i] == ' ') {
            inizioParola = 1;
        }
    }
}

int main() {
    char str[] = "Questo e' un esperimento per l'esercizio IN questione e VErificare se Funziona ";
    
    // Call the function to modify the string
    capitalizzaVocaboli(str);

    // Stampa della stringa modificata
    printf("Stringa modificata: %s\n", str);

    return 0;
}
