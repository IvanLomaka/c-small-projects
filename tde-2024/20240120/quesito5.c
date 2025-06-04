#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Nodo {
    int x;
    int y;
    struct Nodo *next;
} Nodo;

int distanza(Nodo *head) {
    Nodo *current = NULL;
    Nodo *prev = NULL;
    int sum;

    if(head == NULL || head->next == NULL) return -1;

    prev = head;
    current = head->next;

    sum = 0;
    while (current != NULL) {
        sum += abs(current->x - prev->x) + abs(current->y - prev->y);

        prev = current;
        current = prev->next;
    }
    
    return sum;
}

Nodo* creaNodo(int x, int y) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    nuovo->x = x;
    nuovo->y = y;
    nuovo->next = NULL;
    return nuovo;
}

int main(void) {
    int risultato;

    Nodo* temp;    
    Nodo *head = creaNodo(1, 3);
    head->next = creaNodo(4, 3);
    head->next->next = creaNodo(4, 9);
    head->next->next->next = creaNodo(-4, 9);
    head->next->next->next->next = creaNodo(-5, -3);
    head->next->next->next->next->next = creaNodo(2, 1);

    risultato = distanza(head);
    printf("Lunghezza del percorso: %d\n", risultato);

    
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
