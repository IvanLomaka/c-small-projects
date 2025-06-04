#include <stdlib.h>
#include <math.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int isCube(int n) {
    int rad = round(cbrt(n));
    return rad * rad * rad == n;
}

Node *addCube(Node *head) {
    Node *current = NULL;
    Node *temp = NULL;

    current = head;

    while(current != NULL) {
        if(isCube(current->value)) {
            temp = malloc(sizeof(Node));
            if(temp != NULL) {
                temp->value = round(cbrt(current->value));
                temp->next = current->next;
                current->next = temp;
                
                current = current->next;
            } else {
                printf("Errore malloc\n");
                return head;
            }
        } else {
            current = current->next;
        }
    }

    return head;
}

void stampaLista(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("|\n");
}

void aggiungiInFondo(Node **head, int val) {
    Node *nuovo = malloc(sizeof(Node));
    nuovo->value = val;
    nuovo->next = NULL;

    if (*head == NULL) {
        *head = nuovo;
    } else {
        Node *curr = *head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = nuovo;
    }
}

void liberaLista(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int valori[] = {125, 2, 16, 27, 64, -1000, 6, 99, 8, 12, -43};
    int n = sizeof(valori) / sizeof(valori[0]);
    Node *lista = NULL;
    int i;

    for (i = 0; i < n; i++) {
        aggiungiInFondo(&lista, valori[i]);
    }

    printf("Lista iniziale:\n");
    stampaLista(lista);

    addCube(lista);

    printf("Lista modificata:\n");
    stampaLista(lista);

    liberaLista(lista);
    return 0;
}
