#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *removeNode(Node *head, int k) {
    Node *current = head;
    Node *previus = NULL;

    int firstTime = 1;

    while(current != NULL) {
        // se il primo è k
        if(current->value == k && firstTime) {
            return current->next;
        }

        if(current->value == k) {
            previus->next = current->next;
            free(current);
            return head;
        } else {
            firstTime = 0;

            previus = current;
            current = current->next;
        }
    }

    return head;
}

int isPrime(int a) {
    int i = 0;

    if(a == 0 || a == 1) return 0;

    if(a % 2 == 0) return 0;

    for(i = 3; i < a; i = i + 2) {
        if(a % i == 0) return 0;
    }

    return 1;
};

int abs(int a) {
    if(a < 0) return a - (2 * a);

    if(a >= 0) return a;
};

Node *removePrime(Node *head) {
    Node *current = head;

    while (current != NULL) {
        if(isPrime(abs(current->value))) {
            head = removeNode(head, current->value);
        }

        current = current->next;
    }

    return head;
}