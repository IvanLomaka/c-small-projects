#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valore;
    struct Nodo* next;
} Nodo;

// Funzione per inserire un elemento in coda alla lista
Nodo* inserisciInCoda(Nodo* testa, int valore) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->valore = valore;
    nuovoNodo->next = NULL;

    if (testa == NULL) {
        return nuovoNodo;
    }

    Nodo* temp = testa;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nuovoNodo;

    return testa;
}

int checkNext(int value, Nodo *next) {
    Nodo *copia = next;
    int aggiungi = 1;
    if(copia == NULL) return aggiungi;

    while(copia != NULL && aggiungi) {
        if(value < copia->valore) {
            aggiungi = 0;
        }

        copia = copia->next;
    }

    return aggiungi;
}

// Intestazione della funzione richiesta
Nodo* listapicchi(Nodo* lista) {
    if(lista == NULL) return NULL;
    Nodo *current = lista;
    Nodo *check = lista->next;

    Nodo *out = NULL;

    while (current != NULL) {
        if(checkNext(current->valore, check)) {
            out = inserisciInCoda(out, current->valore);
        }
        
        if(check->next != NULL) check = check->next;
        current = current->next;
    }

    

    return out;
}

int main() {
    // Creazione della lista di input
    Nodo* lista = NULL;
    lista = inserisciInCoda(lista, 1);
    lista = inserisciInCoda(lista, 5);
    lista = inserisciInCoda(lista, 13);
    lista = inserisciInCoda(lista, 11);
    lista = inserisciInCoda(lista, 11);
    lista = inserisciInCoda(lista, 4);
    lista = inserisciInCoda(lista, -3);
    lista = inserisciInCoda(lista, 1);
    lista = inserisciInCoda(lista, -5);

    // Chiamata alla funzione listapicchi
    Nodo* listaPicchi = listapicchi(lista);

    // Stampa della lista risultante
    Nodo* temp = listaPicchi;
    while (temp != NULL) {
        printf("%d -> ", temp->valore);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}