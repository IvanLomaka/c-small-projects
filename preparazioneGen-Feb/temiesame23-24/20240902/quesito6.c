#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;


Node *addNode(Node *Head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->next = NULL;
    newNode->value = value;

    if(Head == NULL) return newNode;

    Node *current = Head;
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;

    return Head;
}

int checkExists(Node *head, int value) {
    if(head == NULL) return 0;

    Node *current = head;

    while (current != NULL) {
        if(current->value == value) {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

void freeNode(Node *head) {
    Node *current = NULL;
    while(head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
}

Node *removeDuplicates(Node *head) {
    Node *newList = NULL;
    Node *current = NULL;

    if(head == NULL) return NULL;

    current = head;

    while(current != NULL) {
        if(!checkExists(newList, current->value)) {
            newList = addNode(newList, current->value);
        }

        current = current->next;
    }

    freeNode(head);

    return newList;
}

void printNodes(Node *node) {
    if(node == NULL) return;
    Node *current = node;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Node *head = NULL;
    int n;
    
    while(scanf("%d", &n) && n != 0) {
        if(n != 0) head = addNode(head, n);
    }

    head = removeDuplicates(head);

    printNodes(head);

    return 0;
}