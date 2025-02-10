#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void minmax(Node *head, int *min, int *max) {
    Node *current = head;
    *min = current->value;
    *max = current->value;

    while(current != NULL) {
        if(current->value > *max) *max = current->value;
        if(current->value < *min) *min = current->value;

        current = current->next;
    }
}

int contains(Node *head, int k) {
    Node *current = head;

    while(current != NULL) {
        if(current->value == k) return 1;
        current = current->next;
    }

    return 0;
}

Node *add(Node* head, int k) {
    Node *current = (Node *)malloc(sizeof(Node));

    current->next = NULL;
    current->value = k;

    if(head == NULL) {
        return current;
    }

    Node *now = head;
    while(now->next!=NULL){
        now = now->next;
    }

    now->next = current;

    return head;
}

Node *codici(Node *head) {
    if(head == NULL) return NULL;

    int min, max;
    int i = 0;
    minimax(head, &min, &max);

    Node *newList = NULL;

    for(i = min; i < max; i++) {
        if(!contains(head, i)) {
            newList = add(newList, i);
        }
    }

    return newList;
}