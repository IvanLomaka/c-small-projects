#include <stdio.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
} Nodo;

Nodo *differenzaTraSuccessioni(Nodo *s1, Nodo *s2) {
    Nodo *sottosuccessione = NULL;
    Nodo *nodoUnico = NULL;
    Nodo *ultimo = NULL;

    while (s1) {
        // Se s1->valore non è in s2, aggiungilo alla lista risultante
        if(s2 && s1->valore == s2->valore) {
            s2 = s2->next;  // Scorri s2 se i valori corrispondono
        } else {
            nodoUnico = (Nodo *)malloc(sizeof(Nodo));
            nodoUnico->valore = s1->valore;
            nodoUnico->next = NULL;

            if (ultimo) {
                ultimo->next = nodoUnico;
            } else {
                sottosuccessione = nodoUnico;  // Se è il primo elemento, è la testa della lista
            }

            ultimo = nodoUnico;  // aggiorna l'ultimo nodo
        }
        s1 = s1->next;  // Continua a scorrere la lista s1
    }

    return sottosuccessione;
}
