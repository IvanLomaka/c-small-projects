#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valore;
    struct nodo *next;
} Nodo;

Nodo* ruotaLista(Nodo* testa, int dir) {
    Nodo *current = testa;
    Nodo *newTesta;
    Nodo *newCoda;

    if(dir == 0) {
        newTesta = testa->next;
        newCoda = testa;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newCoda;
        newCoda->next = NULL;
    } else {
        while (current->next->next != NULL) {
            current = current->next;
        }

        newTesta = current->next;
        newCoda = current;

        newCoda->next = NULL;
        newTesta->next = testa;
    }

    return newTesta;
}

Nodo* inserisciInCoda(Nodo* testa, int val) {
    Nodo* nuovo = malloc(sizeof(Nodo));
    Nodo* tmp;
    if (!nuovo) exit(EXIT_FAILURE);
    nuovo->valore = val;
    nuovo->next = NULL;

    if (testa == NULL) return nuovo;

    tmp = testa;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = nuovo;
    return testa;
}

void stampaLista(Nodo* testa) {
    while (testa != NULL) {
        printf("%d -> ", testa->valore);
        testa = testa->next;
    }
    printf("NULL\n");
}

void liberaLista(Nodo* testa) {
    Nodo* tmp;
    while (testa != NULL) {
        tmp = testa;
        testa = testa->next;
        free(tmp);
    }
}

int main(void) {
    Nodo* lista = NULL;

    lista = inserisciInCoda(lista, 3);
    lista = inserisciInCoda(lista, 6);
    lista = inserisciInCoda(lista, 10);
    lista = inserisciInCoda(lista, -2);
    lista = inserisciInCoda(lista, 8);

    printf("Lista originale:\n");
    stampaLista(lista);

    lista = ruotaLista(lista, 0);
    printf("\nDopo rotazione a sinistra:\n");
    stampaLista(lista);

    lista = ruotaLista(lista, 1);
    printf("\nDopo rotazione a destra:\n");
    stampaLista(lista);

    liberaLista(lista);
    return 0;
}
