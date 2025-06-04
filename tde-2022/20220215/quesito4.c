#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void append(Node **head, int value) {
    Node *newNode;
    Node *current;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

Node *checkSub(Node *s1, Node *s2) {
    Node *p1 = NULL;
    Node *p2 = NULL;
    Node *newHead = NULL;

    if(s1 == NULL || s2 == NULL) return NULL;

    p1 = s1;
    p2 = s2;

    while(p1 != NULL) {
        if(p2 != NULL && p1->value == p2->value) {
            p2 = p2->next;
        } else {
            append(&newHead, p1->value);
        }

        p1 = p1->next;
    }

    return newHead;
}

int main(void) {
    Node *s1 = NULL;
    Node *s2 = NULL;
    Node *result = NULL;
    int values1[] = {2, 1, 2, 3, 4, 6, 9};
    int values2[] = {2, 6, 7};
    int i;

    for (i = 0; i < 7; i++) {
        append(&s1, values1[i]);
    }

    for (i = 0; i < 3; i++) {
        append(&s2, values2[i]);
    }

    printf("Lista s1: ");
    printList(s1);
    printf("Lista s2: ");
    printList(s2);

    result = checkSub(s1, s2);
    printf("Lista result: ");
    printList(result);

    return 0;
}
