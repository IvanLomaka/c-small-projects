#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "./dizionario.txt"
#define MAX 25

int anagramma(char s1[], char s2[]) {
    int freq1[256] = {0};
    int freq2[256] = {0};
    int i;

    if (strlen(s1) != strlen(s2)) return 0;

    for (i = 0; s1[i] != '\0'; i++) {
        freq1[(unsigned char)s1[i]]++;
    }

    for (i = 0; s2[i] != '\0'; i++) {
        freq2[(unsigned char)s2[i]]++;
    }

    for (i = 0; i < 256; i++) {
        if (freq1[i] != freq2[i]) return 0;
    }

    return 1;
}

int dimmianagrammi(char parola[]) {
    FILE *fp = NULL;
    char buffer[MAX + 1];
    int counter = 0;

    fp = fopen(FILENAME, "r");

    if(fp == NULL) return -1;

    while(fscanf(fp, "%25s", buffer) == 1) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if(anagramma(parola, buffer)) {
            printf("%s\n", buffer);
            counter++;
        }
    }

    fclose(fp);

    return counter;
}

void convertiInStringa(int n, char s[]) {
    int i = 0;
    int dup = n;

    while(dup > 0) {
        i++;
        dup /= 10;
    }

    s[i] = '\0';

    i--;

    while(n > 0) {
        s[i] = (n % 10) + '0';
        n /= 10;
        i--;
    }
}

int dimmianagrammiNumbers(int num) {
    FILE *fp = NULL;
    char buffer[MAX + 1];
    char numero[MAX + 1];
    int counter = 0;

    fp = fopen(FILENAME, "r");

    if(fp == NULL) return -1;

    convertiInStringa(num, numero);

    while(fscanf(fp, "%25s", buffer) == 1) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if(anagramma(numero, buffer)) {
            printf("%s\n", buffer);
            counter++;
        }
    }

    fclose(fp);

    return counter;
}

int main(void) {
    char parola[26];
    int count;

    printf("Inserisci una parola: ");
    if (scanf("%25s", parola) != 1) {
        printf("Errore nell'inserimento.\n");
        return 1;
    }

    count = dimmianagrammi(parola);

    if (count == -1) {
        printf("Errore nell'apertura del file dizionario.txt.\n");
    } else {
        printf("Numero di anagrammi trovati: %d\n", count);
    }

    return 0;
}
