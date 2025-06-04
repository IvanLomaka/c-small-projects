#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *createMiddle(Node *head, Node *tail, int i) {
    Node *node = NULL;

    node = malloc(sizeof(Node));
    if(node == NULL) {   
        return NULL;
    }

    node->value = i;
    node->next = tail;

    head->next = node;

    return node;
}

Node *order(Node *head) {
    Node *current = NULL;
    Node *next = NULL;
    int i;

    if(head == NULL) return NULL;
    if(head->next == NULL) return head;

    current = head;
    next = head->next;

    while(next != NULL) {
        for(i = current->value + 1; i < next->value; i++) {
            current = createMiddle(current, next, i);
            if(current == NULL) return NULL;
        }
        current = next;
        next = next->next;
    }

    return head;
}

Node *append(Node *head, int value) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    Node *curr;

    newnode->value = value;
    newnode->next = NULL;

    if (head == NULL) return newnode;

    curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newnode;
    return head;
}

void stampa(Node *head) {
    while (head != NULL) {
        printf("%d", head->value);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf(" -|\n");
}

void libera(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void) {
    Node *lista = NULL;

    lista = append(lista, 3);
    lista = append(lista, 6);
    lista = append(lista, 10);

    printf("Lista iniziale:\n");
    stampa(lista);

    order(lista);

    printf("Lista completata:\n");
    stampa(lista);

    libera(lista);
    return 0;
}
