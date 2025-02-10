#include <stdio.h>
#include <string.h>

int StartApp(char []) {
    return 1;
}

int valido(char username[], int min, int max, char speciali[]) {
    int lenuser = strlen(username);
    int lenspec = strlen(speciali);
    int i, j = 0;

    if(lenuser >= min && lenuser <= max) {
        for(i = 0; i < lenuser; i++) {
            for(j = 0; j < lenspec; j++) {
                if(username[i] == speciali[j]) {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}

int main() {
    char username[20];  // Nome utente preimpostato
    int min_length = 8;
    int max_length = 15;
    char special_chars[] = "!@#$&*";  // Caratteri speciali consentiti
    int repeat = 1;
    int risposta;

    while(repeat) {
        scanf("%s", username);
        if(valido(username, min_length, max_length, special_chars)) repeat = 0;
    }

    risposta = StartApp(username);

    return 0;
}