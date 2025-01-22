#include <stdio.h>

int codifica(int valori[], int codice[], int n_valori, int n_codice) {
    int somma = 0;
    int temp[n_valori];

    
    for (int i = 0; i < n_codice; i++) {
        int passi = codice[i] % n_valori;  // Modulo per ottimizzare le rotazioni
        
        if (passi < 0) {
            passi += n_valori;  // Se passi è negativo, lo facciamo positivo
        }

        // Eseguiamo la rotazione a destra
        for (int j = 0; j < n_valori; j++) {
            temp[j] = valori[(j - passi + n_valori) % n_valori];
        }
        
        // Copiamo l'array ruotato in 'valori'
        for (int j = 0; j < n_valori; j++) {
            valori[j] = temp[j];
        }
        
        // Sommiamo il primo elemento dopo la rotazione
        somma += valori[0];
    }

    return somma;
}

int main() {
    int valori[] = {3, 1, -4, 2, 0, 5};
    int codice[] = {-2, 3, 1, 8};
    int n_valori = sizeof(valori) / sizeof(valori[0]);
    int n_codice = sizeof(codice) / sizeof(codice[0]);

    int risultato = codifica(valori, codice, n_valori, n_codice);
    printf("La somma dei valori all'inizio dell'array dopo ogni rotazione è: %d\n", risultato);

    return 0;
}
