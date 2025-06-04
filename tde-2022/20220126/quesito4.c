#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int checkSub(Node *s1, Node *s2) {
    Node *p1 = NULL;
    Node *p2 = NULL;

    if(s1 == NULL || s2 == NULL) return 0;

    p1 = s1;
    p2 = s2;

    while(p1 != NULL && p2 != NULL) {
        if(p1->value == p2->value) {
            p2 = p2->next;
        }

        p1 = p1->next;
    }

    if(p2 == NULL) return 1;

    return 0;
}

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

int main(void) {
    Node *s1 = NULL;
    Node *s2 = NULL;
    int values1[] = {2, 1, 2, 3, 4, 6, 9};
    int values2[] = {2, 6, 7};
    int i, result;

    for (i = 0; i < 8; i++) {
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
    if (result)
        printf("s2 è sottosuccessione di s1.\n");
    else
        printf("s2 NON è sottosuccessione di s1.\n");

    return 0;
}
