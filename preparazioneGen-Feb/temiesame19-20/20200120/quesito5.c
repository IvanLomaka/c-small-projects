#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* rotateleft(Node *head) {
    Node* first = head;  // Il primo nodo
    Node* second = head->next;  // Il secondo nodo
    Node* current = head;

    // Trova l'ultimo nodo
    while (current->next != NULL) {
        current = current->next;
    }

    // Sposta il primo nodo alla fine
    current->next = first;
    first->next = NULL;

    return second;  // La nuova testa è il secondo nodo
}

Node *rotateright(Node *head) {
    Node* current = head;
    
    // Trova il penultimo nodo
    while (current->next->next != NULL) {
        current = current->next;
    }

    Node* last = current->next;  // L'ultimo nodo
    current->next = NULL;  // Rimuove l'ultimo nodo dalla lista
    last->next = head;  // Imposta l'ultimo nodo come primo

    return last;  // La nuova testa è l'ultimo nodo
}

Node* rotate(Node* head, int dir) {
    Node *rotated = NULL;
    if(head == NULL) return NULL;
    if(head -> next == NULL) return head;

    if(dir == 0) {
        rotated = rotateleft(head);
    } else {
        rotated = rotateright(head);
    }

    return rotated;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Creazione della lista: 3 → 6 → 10 → −2 → 8
    Node *head = (Node*)malloc(sizeof(Node));
    head->value = 3;
    
    Node *second = (Node*)malloc(sizeof(Node));
    second->value = 6;
    head->next = second;

    Node *third = (Node*)malloc(sizeof(Node));
    third->value = 10;
    second->next = third;

    Node *fourth = (Node*)malloc(sizeof(Node));
    fourth->value = -2;
    third->next = fourth;

    Node *fifth = (Node*)malloc(sizeof(Node));
    fifth->value = 8;
    fourth->next = fifth;
    fifth->next = NULL;

    printf("Lista originale: ");
    printList(head);

    // Rotazione a sinistra (dir = 0)
    head = rotate(head, 0);
    printf("Dopo rotazione a sinistra: ");
    printList(head);

    // Rotazione a destra (dir = 1)
    head = rotate(head, 1);
    printf("Dopo rotazione a destra: ");
    printList(head);

    return 0;
}
