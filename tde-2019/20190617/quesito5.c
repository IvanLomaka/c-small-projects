#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *append(Node *head, int val) {
    Node *new = malloc(sizeof(Node));
    Node *curr;
    new->data = val;
    new->next = NULL;

    if (head == NULL) return new;

    curr = head;
    while (curr->next != NULL) curr = curr->next;
    curr->next = new;
    return head;
}

void stampa(Node *head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

void libera(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int conta(Node *head, int value) {
    Node *current = head;
    int counter = 0;

    while(current != NULL) {
        if(current->data == value) counter++;
        current = current->next;
    }

    return counter;
}

Node *removeAll(Node *head, int value) {
    Node *current = NULL;
    Node *prev = NULL;
    Node *temp = NULL;

    current = head;

    while (current != NULL) {
        if(current->data == value) {
            temp = current;
            if(prev == NULL) {
                head = current->next;
                current = head;
            } else {
                prev->next = current->next;
                current = current->next;
            }
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

Node *filtra(Node *head, int x) {
    Node *current = NULL;

    current = head;

    while(current != NULL) {
        if(conta(head, current->data) >= x) {
            head = removeAll(head, current->data);
            current = head;
        } else {
            current = current->next;
        }
    }

    return head;
}

int main(void) {
    Node *head = NULL;
    Node *risultato = NULL;
    int x = 3;

    int valori[] = {3, 3, 1, 2, 4, 3, 5, 3, 5, 4};
    int len = sizeof(valori) / sizeof(valori[0]);
    int i;

    for (i = 0; i < len; i++) {
        head = append(head, valori[i]);
    }

    printf("Lista originale:\n");
    stampa(head);

    risultato = filtra(head, x);

    printf("\nLista risultante (escludendo elementi che appaiono almeno %d volte):\n", x);
    stampa(risultato);

    return 0;
}
