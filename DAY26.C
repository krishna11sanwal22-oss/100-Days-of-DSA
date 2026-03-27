#include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// Function to insert at end
void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;

    // Traverse to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link new node
    temp->next = newNode;
    newNode->prev = temp;
}

// Forward traversal
void displayForward() {
    struct Node* temp = head;
    printf("Forward Traversal: ");
    
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Backward traversal
void displayBackward() {
    struct Node* temp = head;

    // Move to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Backward Traversal: ");
    
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        insertEnd(value);
    }

    displayForward();
    displayBackward();

    return 0;
}