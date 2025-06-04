#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *aggiungi(Node* head, int value) {
    Node *current = NULL;
    Node *nodo = NULL;

    nodo = malloc(sizeof(Node));
    if(nodo == NULL) return head;

    nodo->next = NULL;
    nodo->value = value;

    if(head == NULL) return nodo;

    current = head;

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = nodo;

    return head;
}

int isPrime(int n) {
    int i;

    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    
    for(i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return 0;
    }

    return 1;
}


Node *eliminaPrimi(Node *head) {
    Node *current = NULL;
    Node *check = NULL;
    Node *prev = NULL;

    if(head == NULL) return head;

    current = head;

    while(current != NULL) {
        prev = current;
        check = current->next;

        while(check != NULL) {
            if(check->value < current->value && isPrime(check->value)) {
                prev->next = check->next;
                free(check);
                check = prev->next;
            } else {
                prev = check;
                check = check->next;
            }
        }

        current = current->next;
    }

    return head;
}

void stampaLista(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("|\n");
}

void liberaLista(Node *head) {
    Node *curr = head;
    Node *temp;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main(void) {
    int valori[] = {5, 2, 15, 17, 7, 11, 4, 10};
    int n = sizeof(valori) / sizeof(valori[0]);
    int i;
    Node *head = NULL;

    for (i = 0; i < n; i++) {
        head = aggiungi(head, valori[i]);
    }

    printf("Lista iniziale:\n");
    stampaLista(head);

    head = eliminaPrimi(head);

    printf("Lista dopo eliminazione:\n");
    stampaLista(head);

    liberaLista(head);

    return 0;
}
