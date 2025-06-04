#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

void printlist(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

Node * append(Node *head, int val) {
    Node *newNode = malloc(sizeof(Node));
    Node *curr;

    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = newNode;
    return head;
}

Node * listapicchi(Node *head) {
    Node *current = NULL;
    Node *next = NULL;
    Node *newList = NULL;

    int isPeak;

    if(head == NULL) return NULL;

    current = head;

    if(current->next == NULL) {
        newList = append(newList, current->val);
        return newList;
    }

    next = current->next;

    while(current->next != NULL) {
        isPeak = 1;

        next = current->next;
        while(next != NULL) {
            if(current->val <= next->val) isPeak = 0;
            next = next->next;
        }

        if(isPeak) newList = append(newList, current->val);

        current = current->next;    
    }

    newList = append(newList, current->val);

    return newList;
}

int main(void) {
    Node *lista = NULL;
    Node *picchi;

    int valori[] = {1, 5, 13, 11, 11, 4, -3, 1, -5};
    int n = sizeof(valori) / sizeof(valori[0]);
    int i;

    for(i = 0; i < n; i++) {
        lista = append(lista, valori[i]);
    }

    printf("Lista originale:\n");
    printlist(lista);

    picchi = listapicchi(lista);

    printf("Lista dei picchi:\n");
    printlist(picchi);

    return 0;
}
