#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *appendCheck(Node *head, int value) {
    Node *current = NULL;
    Node *agg = NULL;

    agg = malloc(sizeof(Node));
    if(agg == NULL) return NULL;

    agg->value = value;
    agg->next = NULL;

    if(head == NULL) return agg;

    current = head;

    while(current->next != NULL) current = current->next;

    if(current->value == agg->value) {
        free(agg);
        return head;
    }

    current->next = agg;

    return head;
}

Node *append(Node *head, int value) {
    Node *current = NULL;
    Node *agg = NULL;

    agg = malloc(sizeof(Node));
    if(agg == NULL) return NULL;

    agg->value = value;
    agg->next = NULL;

    if(head == NULL) return agg;

    current = head;

    while(current->next != NULL) current = current->next;

    current->next = agg;

    return head;
}

Node *sommaLista(Node *l1, Node *l2) {
    Node *cl1 = NULL;
    Node *cl2 = NULL;
    Node *newList = NULL;

    cl1 = l1;
    cl2 = l2;

    while(cl1 != NULL || cl2 != NULL) {

        if((cl2 == NULL) || (cl1 != NULL && cl1->value < cl2->value)) {
            newList = appendCheck(newList, cl1->value);
            cl1 = cl1->next;
            
        } else {
            newList = appendCheck(newList, cl2->value);
            cl2 = cl2->next;
        }
    }

    return newList;
}

Node *createList(int arr[], int len) {
    Node *head = NULL;
    int i;
    for (i = 0; i < len; i++) {
        head = append(head, arr[i]);
    }
    return head;
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%d", head->value);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    int arr1[] = {-5, -5, -1, 7, 12, 15, 20, 100};
    int arr2[] = {-6, -2, -1, 0, 0, 3, 7, 7, 15, 101};

    Node *l1 = createList(arr1, sizeof(arr1)/sizeof(arr1[0]));
    Node *l2 = createList(arr2, sizeof(arr2)/sizeof(arr2[0]));

    Node *l3 = sommaLista(l1, l2);

    printf("Lista unione (senza duplicati, ordinata):\n");
    printList(l3);

    return 0;
}
