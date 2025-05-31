#include <stdio.h>
#include <stdlib.h>

/* Definizione del nodo di lista */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Prototipi */
Node* createList(int arr[], int n);
void freeList(Node *head);

int containsWithK(Node *l1, Node *l2, int k) {
    if (l1 == NULL || l2 == NULL)
        return 0;

    int currentSkip = 0;
    int started = 0;
    Node *l1copy = l1;
    Node *l2copy = l2;

    while (l1copy != NULL && l2copy != NULL) {
        if (currentSkip > k) return 0;
        if (l1copy->data == l2copy->data) {

            started = 1;
            currentSkip = 0;
            l1copy = l1copy->next;
            l2copy = l2copy->next;

        } else {

            if(started) currentSkip += 1;
            l1copy = l1copy->next;

        }
    }

    if(l2copy == NULL) return 1;

    return 0;
}


/* Funzione main con i tre casi di test della traccia */
int main(void) {
    /* --- Caso 1 --- */
    int a1[] = {9, 4, 1, 2, -4, 7, -2, 6, 8, 5};
    int b1[] = {2, -2, 6};
    Node *l1 = createList(a1, sizeof(a1)/sizeof(a1[0]));
    Node *l2 = createList(b1, sizeof(b1)/sizeof(b1[0]));
    int k = 2;
    printf("Caso 1 (k=%d): %d\n", k, containsWithK(l1, l2, k));  // atteso 1
    freeList(l1);
    freeList(l2);

    /* --- Caso 2 --- */
    l1 = createList(a1, sizeof(a1)/sizeof(a1[0]));
    l2 = createList(b1, sizeof(b1)/sizeof(b1[0]));
    k = 1;
    printf("Caso 2 (k=%d): %d\n", k, containsWithK(l1, l2, k));  // atteso 0
    freeList(l1);
    freeList(l2);

    /* --- Caso 3 --- */
    int a3[] = {9, 4, 1, 2, -4, 7, -2, 6, 8, 0};
    int b3[] = {2, 5, 6};
    l1 = createList(a3, sizeof(a3)/sizeof(a3[0]));
    l2 = createList(b3, sizeof(b3)/sizeof(b3[0]));
    k = 2;
    printf("Caso 3 (k=%d): %d\n", k, containsWithK(l1, l2, k));  // atteso 0
    freeList(l1);
    freeList(l2);

    return 0;
}

/* Crea una lista concatenata da un array */
Node* createList(int arr[], int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        Node *p = malloc(sizeof(Node));
        if (!p) exit(EXIT_FAILURE);
        p->data = arr[i];
        p->next = NULL;
        if (!head) head = p;
        else tail->next = p;
        tail = p;
    }
    return head;
}

/* Libera tutta la lista */
void freeList(Node *head) {
    while (head) {
        Node *t = head->next;
        free(head);
        head = t;
    }
}