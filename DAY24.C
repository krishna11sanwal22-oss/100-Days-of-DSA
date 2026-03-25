#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at end
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

// Function to delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;

    // Case 1: if head itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Case 2: search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL) {
        return head;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);

    return head;
}

// Function to display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int n, x, key;
    struct Node* head = NULL;

    // Input number of elements
    scanf("%d", &n);

    // Input list elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    // Input key
    scanf("%d", &key);

    // Delete first occurrence
    head = deleteKey(head, key);

    // Output updated list
    display(head);

    return 0;
}