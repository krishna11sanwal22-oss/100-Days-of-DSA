#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Main function
int main() {
    // Creating sample linked list: 10 -> 20 -> 30 -> NULL
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 20;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 30;

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = NULL;

    int total = countNodes(head);
    printf("Total nodes = %d\n", total);

    return 0;
}