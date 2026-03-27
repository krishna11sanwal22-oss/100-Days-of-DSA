#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create circular linked list
void create(int n) {
    struct Node *newNode, *temp;
    int value;

    if (n <= 0) return;

    // Create first node
    printf("Enter value: ");
    scanf("%d", &value);

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = value;
    head->next = head;  // circular link

    temp = head;

    // Create remaining nodes
    for (int i = 2; i <= n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        newNode->next = head;   // point to head
        temp->next = newNode;   // link previous node

        temp = newNode;
    }
}

// Traversal function
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// Main function
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    create(n);
    display();

    return 0;
}