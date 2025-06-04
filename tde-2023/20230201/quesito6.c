#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *aggiungi(Node *head, int value) {
    Node *current = NULL;
    Node *agg = NULL;

    agg = malloc(sizeof(Node));

    if(agg == NULL) return NULL;

    agg->value = value;
    agg->next = NULL;

    if(head == NULL) {
        return agg;
    }

    current = head;

    while(current->next != NULL) current = current->next;

    current->next = agg;

    return head;
}

Node *riduci(Node *head) {
    Node *current;
    Node *temp;
    int sum;

    current = head;

    while (current->next != NULL) {
        temp = current->next;
        sum = current->value + temp->value;

        current->value = sum;
        current->next = temp->next;

        free(temp);

        current = current->next;
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

void liberaLista(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void) {
    int valori[] = {21, -3, 12, 11, 3, -9, 5};
    int n = sizeof(valori) / sizeof(valori[0]);
    int i;
    Node *lista = NULL;
    for (i = 0; i < n; i++) {
        lista = aggiungi(lista, valori[i]);
    }

    printf("Lista iniziale:\n");
    stampaLista(lista);

    lista = riduci(lista);

    printf("Lista ridotta:\n");
    stampaLista(lista);

    liberaLista(lista);
    return 0;
}
