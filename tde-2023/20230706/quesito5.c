#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *aggiungi(Node *head, int value) {
    Node *current = NULL;
    Node *agg = NULL;

    agg = malloc(sizeof(Node));

    agg->value = value;
    agg->next = NULL;

    if(head == NULL) return agg;

    current = head;

    while(current->next != NULL) current = current->next;

    current->next = agg;

    return head;
}

int check(Node *h1, Node *h2, int k) {
    Node *current = h1;
    Node *c1, *c2;
    int counter;

    if(h1 == NULL || h2 == NULL) return 0;

    while(current != NULL) {
        c1 = current;
        c2 = h2;
        counter = 0;

        while(c2 != NULL && c1 != NULL) {
            if(c1->value == c2->value) {
                counter = 0;
                c2 = c2->next;
            } else {
                counter++;
            }

            if(counter > k) break;

            c1 = c1->next;
        }

        if(c2 == NULL) return 1;

        current = current->next;
    }

    return 0;
}

Node *creaListaDaArray(int arr[], int len) {
    Node *head = NULL;
    int i;
    for (i = 0; i < len; i++) {
        head = aggiungi(head, arr[i]);
    }
    return head;
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
    Node *l1, *l2;
    int r;

    /* Test 1 */
    {
        int v1[] = {9, 4, 1, 2, -4, 7, -2, 6, 8, 5};
        int v2[] = {2, -2, 6};
        l1 = creaListaDaArray(v1, 10);
        l2 = creaListaDaArray(v2, 3);
        r = check(l1, l2, 2);
        printf("Test 1 (atteso 1): %d\n", r);
        liberaLista(l1);
        liberaLista(l2);
    }

    /* Test 2 */
    {
        int v1[] = {9, 4, 1, 2, -4, 7, -2, 6, 8, 5};
        int v2[] = {2, -2, 6};
        l1 = creaListaDaArray(v1, 10);
        l2 = creaListaDaArray(v2, 3);
        r = check(l1, l2, 1);
        printf("Test 2 (atteso 0): %d\n", r);
        liberaLista(l1);
        liberaLista(l2);
    }

    /* Test 3 */
    {
        int v1[] = {9, 4, 1, 2, -4, 7, -2, 6, 8, 0};
        int v2[] = {2, 5, 6};
        l1 = creaListaDaArray(v1, 10);
        l2 = creaListaDaArray(v2, 3);
        r = check(l1, l2, 2);
        printf("Test 3 (atteso 0): %d\n", r);
        liberaLista(l1);
        liberaLista(l2);
    }

    return 0;
}
