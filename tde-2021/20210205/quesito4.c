#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LEN 30

typedef struct Node {
    char *string;
    struct Node *next;
} Node;

Node *push(Node *head, char string[]) {
    Node *node = NULL;
    Node *current = NULL;

    node = (Node *)malloc(sizeof(Node));
    if(node == NULL) return NULL;

    node->string = (char *)malloc(sizeof(char) * strlen(string));
    if(node->string == NULL) {
        free(node);
        return NULL;
    }

    strcpy(node->string, string);
    node->next = NULL;

    if(head == NULL) {
        return node;
    }

    current = head;

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = node;

    return head;
}

int visualizzaalternative(char cerca[], FILE *fp, int maxLen) {
    int vocaboli = 0;
    char vocabolo[MAX_LEN + 2];

    while(fgets(vocabolo, maxLen + 1, fp) != NULL) {
        vocabolo[strcspn(vocabolo, "\n")] = '\0';

        if(strlen(vocabolo) == strlen(cerca) &&
            strcmp(vocabolo + 1, cerca + 1) == 0 &&
            vocabolo[0] != cerca[0]) {
            printf("%s\n", vocabolo);
            vocaboli++;
        }
    }

    return vocaboli;
}

Node *visualizzaalternativev2(char cerca[], FILE *fp, int maxLen, int *num) {
    Node *head = NULL;
    char vocabolo[MAX_LEN + 2];

    *num = 0;
    
    while(fgets(vocabolo, maxLen + 1, fp) != NULL) {
        vocabolo[strcspn(vocabolo, "\n")] = '\0';
        
        if(strlen(vocabolo) == strlen(cerca) &&
            strcmp(vocabolo + 1, cerca + 1) == 0 &&
            vocabolo[0] != cerca[0]) {
            head = push(head, vocabolo);
            if(head == NULL) return NULL;
            *num += 1;
        }
    }

    return head;
}

void printHead(Node *head) {
    Node *current = NULL;

    current = head;
    
    while(current != NULL) {
        printf("%s\n", current->string);
        current = current->next;
    }
}

void freeNode(Node *head) {
    Node *current = NULL;
    Node *prev = NULL;

    current = head;
    
    while(current != NULL) {
        prev = current;
        current = current->next;
        free(prev);
    }

    free(current);
}

int main(int argc, char *argv[]) {
    int num;
    Node *head = NULL;
    FILE *fp = NULL;

    if(argc != 2) return 1;

    fp = fopen("./dizionario.txt", "r");

    head = visualizzaalternativev2(argv[1], fp, MAX_LEN, &num);

    if(head == NULL) return 1;

    printHead(head);

    printf("%d\n", num);

    freeNode(head);

    return 0;
}
