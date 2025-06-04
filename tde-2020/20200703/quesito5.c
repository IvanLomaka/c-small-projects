#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int isPrime(int n) {
    int i = 0;

    n = abs(n);
    
    if (n <= 1) return 0;
    
    if (n == 2) return 1;
    
    if (n % 2 == 0) return 0;
    
    for(i = 3; i < n; i += 2) {
        if(n % i == 0) return 0;
    }

    return 1;
}

Node *remove_if_abs_prime(Node *head) {
    Node *current = NULL;
    Node *prev = NULL;
    Node *temp = NULL;

    current = head;

    while(current != NULL) {
        if(isPrime(current->value)) {
            temp = current;
            if(prev == NULL) {
                head = current->next;
                current = head;
                free(temp);
            } else {
                prev->next = current->next;
                current = current->next;
                free(temp);
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

int main(void) {
    Node *list = NULL;
    Node *curr = NULL;
    Node *tmp = NULL;
    Node *n1 = NULL;
    Node *n2 = NULL;
    Node *n3 = NULL;
    Node *n4 = NULL;

    n1 = malloc(sizeof(Node)); n1->value = -3;
    n2 = malloc(sizeof(Node)); n2->value = 4;
    n3 = malloc(sizeof(Node)); n3->value = -5;
    n4 = malloc(sizeof(Node)); n4->value = 6;

    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = NULL;
    list = n1;

    list = remove_if_abs_prime(list);

    curr = list;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }

    return 0;
}
