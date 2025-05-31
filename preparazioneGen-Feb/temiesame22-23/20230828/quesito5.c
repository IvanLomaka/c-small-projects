#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Function to add a node to the end of the list and return the head
Node* addNode(Node *head, char value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL; // Memory allocation failed
    }
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node; // If the list is empty, new_node becomes the head
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;

    return head; // Return the head of the list
}

// Declare the subprogram (you will implement this)
Node* create_l3(Node* l1, Node* l2) {
    Node* l3 = NULL;
    char add;

    while (l1 != NULL || l2 != NULL) {
        char c1 = (l1 != NULL) ? l1->data : 127; // Use 127 (DEL) as a placeholder if l1 is exhausted
        char c2 = (l2 != NULL) ? l2->data : 127; // Use 127 (DEL) as a placeholder if l2 is exhausted

        // Choose the smaller character
        char smaller_char = (c1 < c2) ? c1 : c2;

        // Add the smaller character to l3
        l3 = addNode(l3, smaller_char);
    
        // Move to the next node in l1 and l2 if they exist
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return l3;
};

// Helper function to create a linked list from an array of characters
Node* create_list(char arr[], int size) {
    Node* head = NULL;
    Node* temp = NULL;
    for (int i = 0; i < size; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = arr[i];
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            temp = head;
        } else {
            temp->next = new_node;
            temp = temp->next;
        }
    }
    return head;
}

// Helper function to print a linked list
void print_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Example input lists
    char arr1[] = {'a', 'c', 'e'};
    char arr2[] = {'b', 'd', 'f', 'g'};

    // Create l1 and l2
    Node* l1 = create_list(arr1, sizeof(arr1) / sizeof(arr1[0]));
    Node* l2 = create_list(arr2, sizeof(arr2) / sizeof(arr2[0]));

    // Print l1 and l2
    printf("List l1: ");
    print_list(l1);
    printf("List l2: ");
    print_list(l2);

    // Call the subprogram to create l3
    Node* l3 = create_l3(l1, l2);

    // Print l3
    printf("List l3: ");
    print_list(l3);

    // Free memory (optional, but good practice)
    // You can write a function to free the linked lists if needed

    return 0;
}