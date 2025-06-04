#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *removePeak(Node *head) {
    Node *prev = NULL;
    Node *current = NULL;
    Node *next = NULL;

    if(head == NULL || head->next == NULL || head->next->next == NULL) return head;

    prev = head;
    current = head->next;
    next = head->next->next;

    while (prev != NULL && current != NULL && next != NULL) {
        if(current->value > prev->value && current->value > next->value) {
            prev->next = next;
            free(current);
        }

        next = next->next;

        prev = next;
        if(prev != NULL) current = prev->next;
        if(current != NULL) next = current->next;
    }

    return head;
}

Node *aggiungi(Node *head, int value) {
    Node *newNode;
    Node *current;

    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) exit(1);
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

void stampaLista(Node *head) {
    while (head != NULL) {
        printf("%d", head->value);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf(" -|\n");
}

void liberaLista(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void) {
    int i;
    int values[] = {1, 2, 3, 1, 7, 5, -4, 5, 4, 1, 2};
    int n = sizeof(values) / sizeof(values[0]);

    Node *lista = NULL;

    for (i = 0; i < n; i++) {
        lista = aggiungi(lista, values[i]);
    }

    printf("Lista iniziale:\n");
    stampaLista(lista);

    lista = removePeak(lista);

    printf("Lista dopo la rimozione dei picchi centrali:\n");
    stampaLista(lista);

    liberaLista(lista);
    return 0;
}
