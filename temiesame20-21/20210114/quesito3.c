#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Funzione per creare un nuovo nodo
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Errore di allocazione memoria\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Funzione per aggiungere un nodo in coda alla lista
void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Funzione per stampare la lista
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

// Funzione per verificare se un valore è già presente nella lista
int isPresent(Node* head, int value) {
    while (head != NULL) {
        if (head->value == value)
            return 1;
        head = head->next;
    }
    return 0;
}

// Funzione per compattare la lista rimuovendo duplicati e zeri
void compactList(Node** head) {
    if (*head == NULL)
        return;

    Node* newHead = NULL;
    Node* current = *head;

    while (current != NULL) {
        if (current->value != 0 && !isPresent(newHead, current->value)) {
            append(&newHead, current->value);
        }
        current = current->next;
    }

    // Libera la memoria della vecchia lista
    while (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *head = newHead; // Assegna la nuova lista compatta
}

// Funzione per creare la lista di esempio
Node* createSampleList() {
    int values[] = {1, 3, 5, -2, 3, -1, 0, 2, 4, 1};
    int n = sizeof(values) / sizeof(values[0]);

    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        append(&head, values[i]);
    }

    return head;
}

// Funzione principale
int main() {
    Node* head = createSampleList();

    printf("Lista originale:\n");
    printList(head);

    compactList(&head);

    printf("Lista compatta:\n");
    printList(head);

    return 0;
}