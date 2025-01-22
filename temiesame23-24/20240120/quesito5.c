#include <stdio.h>
#include <stdlib.h>

// Definizione del tipo di dato per il punto
typedef struct Punto {
    int x;
    int y;
    struct Punto* next;
} Punto;

// Dichiarazione del sottoprogramma
int calcolaLunghezzaPercorso(Punto* lista) {
    Punto* currentPoint = lista;
    Punto* nextPoint = lista->next;

    int distanza = 0;
    int distanzaX = 0;
    int distanzaY = 0;

    while (currentPoint->next != NULL) {
        distanzaX = currentPoint->x - nextPoint->x;

        if(distanzaX < 0) {
            distanzaX += 2*(-distanzaX);
        }

        distanzaY = currentPoint->y - nextPoint->y;
        if(distanzaY < 0) {
            distanzaY += 2*(-distanzaY);
        }

        distanza += distanzaX + distanzaY;

        currentPoint = nextPoint;
        nextPoint = nextPoint -> next;
    }

    return distanza;
}

int main() {
    // Creazione manuale della lista di punti per test
    Punto* p1 = (Punto*)malloc(sizeof(Punto));
    Punto* p2 = (Punto*)malloc(sizeof(Punto));
    Punto* p3 = (Punto*)malloc(sizeof(Punto));
    
    p1->x = 1; p1->y = 3; p1->next = p2;
    p2->x = 4; p2->y = 3; p2->next = p3;
    p3->x = 4; p3->y = 7; p3->next = NULL;

    // Chiamata al sottoprogramma
    int lunghezzaPercorso = calcolaLunghezzaPercorso(p1);

    // Stampa del risultato
    printf("La lunghezza del percorso è: %d\n", lunghezzaPercorso);

    // Pulizia della memoria
    free(p1);
    free(p2);
    free(p3);

    return 0;
}
