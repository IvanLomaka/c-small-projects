#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
} Nodo;

int calcolaLunghezza(Nodo* testa) {
    int len = 1;

    if(testa == NULL) return 0;

    while (testa->next != NULL) {
        testa = testa->next;
        len++;
    }

    return len;
}

Nodo* trovaDaFine(Nodo* testa, int k) {
    Nodo *current = testa;
    int lunghezza = calcolaLunghezza(testa);
    int i;

    if(k > lunghezza) return NULL;

    for (i = 0; i < lunghezza - k; i ++) {
        current = current->next;
    }

    return current;
}

int main(void) {
    Nodo* lista = NULL;
    Nodo* risultato;
    int k = 21;

    lista = malloc(sizeof(Nodo)); lista->valore = 10;
    lista->next = malloc(sizeof(Nodo)); lista->next->valore = 20;
    lista->next->next = malloc(sizeof(Nodo)); lista->next->next->valore = 30;
    lista->next->next->next = malloc(sizeof(Nodo)); lista->next->next->next->valore = 40;
    lista->next->next->next->next = malloc(sizeof(Nodo)); lista->next->next->next->next->valore = 50;
    lista->next->next->next->next->next = NULL;

    risultato = trovaDaFine(lista, k);

    if (risultato != NULL)
        printf("Elemento in posizione %d dalla fine: %d\n", k, risultato->valore);
    else
        printf("Nessun elemento in posizione %d dalla fine.\n", k);

    return 0;
}
