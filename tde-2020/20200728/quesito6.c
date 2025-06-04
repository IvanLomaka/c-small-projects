#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int index;
    struct Node *next;
} Node;

Node *createAppend(Node *tail, int index) {
    Node *node = NULL;

    node = malloc(sizeof(Node));

    node->next = NULL;
    node->index = index;

    if(tail == NULL) {
        return node;
    }

    tail->next = node;

    return node;
}

Node *filtra_indici(int seq[], int len, int soglia) {
    Node *head = NULL;
    Node *current = NULL;
    int i;

    for(i = 0; i < len; i++) {
        if(seq[i] > (soglia * soglia)) {
            if(head == NULL) {
                head = createAppend(head, i);
                current = head;
            } else {
                current = createAppend(current, i);
            }
        }
    }

    return head;
}

int main(void) {
    int seq[] = {3, 20, 4, 15, 30, 2};
    int len = sizeof(seq) / sizeof(seq[0]);
    int soglia = 4;
    Node *lista;
    Node *curr;
    Node *tmp;

    lista = filtra_indici(seq, len, soglia);

    printf("Indici con valori maggiori di %d^2:\n", soglia);
    curr = lista;
    while (curr != NULL) {
        printf("%d ", curr->index);
        curr = curr->next;
    }
    printf("\n");

    
    while (lista != NULL) {
        tmp = lista;
        lista = lista->next;
        free(tmp);
    }

    return 0;
}
