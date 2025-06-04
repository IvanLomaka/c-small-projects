#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int num;
    struct Node *next;
} Node;

typedef struct BigNode {
    int num;
    int occ;
    struct BigNode *next;
} BigNode;

Node *append(Node *head, int val) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    Node *curr;
    newnode->num = val;
    newnode->next = NULL;

    if (head == NULL) return newnode;

    curr = head;
    while (curr->next != NULL) curr = curr->next;
    curr->next = newnode;
    return head;
}

void stampaNode(Node *head) {
    while (head != NULL) {
        printf("%d", head->num);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf(" |\n");
}

void stampaBigNode(BigNode *head) {
    while (head != NULL) {
        printf("(%d, %d)", head->num, head->occ);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf(" |\n");
}

void liberaNode(Node *head) {
    Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void liberaBigNode(BigNode *head) {
    BigNode *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

BigNode *inserisci_ordinato(BigNode *head, int val) {
    BigNode *curr = head;
    BigNode *prev = NULL;
    BigNode *newnode;

    while (curr != NULL && curr->num < val) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL && curr->num == val) {
        curr->occ += 1;
        return head;
    }

    newnode = (BigNode *)malloc(sizeof(BigNode));
    if (newnode == NULL) return head;

    newnode->num = val;
    newnode->occ = 1;
    newnode->next = curr;

    if (prev == NULL) {
        head = newnode;
    } else {
        prev->next = newnode;
    }

    return head;
}

BigNode *compactlist(Node *head) {
    BigNode *newHead = NULL;
    Node *curr = head;

    while (curr != NULL) {
        newHead = inserisci_ordinato(newHead, curr->num);
        curr = curr->next;
    }

    return newHead;
}

int main(void) {
    Node *original = NULL;
    BigNode *compatta = NULL;

    int values[] = {3, 3, 1, 2, 4, 3, -5, 3, -5, 4};
    int len = sizeof(values) / sizeof(values[0]);
    int i;

    for (i = 0; i < len; i++) {
        original = append(original, values[i]);
    }

    printf("Lista originale:\n");
    stampaNode(original);

    compatta = compactlist(original);

    printf("Lista compatta (valore, occorrenze):\n");
    stampaBigNode(compatta);

    liberaNode(original);
    liberaBigNode(compatta);

    return 0;
}
