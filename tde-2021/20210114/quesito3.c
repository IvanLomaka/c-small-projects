#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *delete(Node *head, int value, int times) {
    Node *current = NULL;
    Node *prev = NULL;
    Node *temp = NULL;
    int occ = 0;

    current = head;

    while(current != NULL) {
        if(current->value == value) {
            occ ++;
            if(occ > times) {
                temp = current;
                if(prev == NULL) {
                    head = current->next;
                    current = head;
                } else {
                    prev->next = current->next;
                    current = current->next;
                }
                free(temp);
            } else {
                prev = current;
                current = current->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

Node *compatta(Node *head) {
    Node *current = NULL;

    current = head;

    while(current->next != NULL) {
        head = delete(head, current->value, 1);
        current = current->next;
    }

    head = delete(head, 0, 0);

    return head;
}

/* Function to print a linked list */
void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL)
            printf(" → ");
        current = current->next;
    }
    printf("\n");
}

/* Function to create a new node */
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

/* Function to append a node at the end of a list */
Node* appendNode(Node* head, int value) {
    Node* newNode = createNode(value);
    Node* current = head;
    
    if (head == NULL) {
        return newNode;
    }
    
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    
    return head;
}

int main(void) {
    Node *head = NULL;
    int values[] = {1, 3, 5, -2, 3, -1, 0, 2, 4, 1};
    int numValues = sizeof(values) / sizeof(values[0]);
    int i;
    Node *current = NULL;
    Node *temp = NULL;
    
    for (i = 0; i < numValues; i++) {
        head = appendNode(head, values[i]);
    }
    
    /* Print the original list */
    printf("Original list: ");
    printList(head);
    
    /* Compact the list */
    head = compatta(head);
    
    /* Print the compacted list */
    printf("Compacted list: ");
    printList(head);
    
    /* Free memory */
    {
        current = head;
        temp = NULL;
        
        while (current != NULL) {
            temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    return 0;
}
