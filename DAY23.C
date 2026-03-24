#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

// Function to display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // List 1: 1 -> 3 -> 5
    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 5);

    // List 2: 2 -> 4 -> 6
    list2 = insertEnd(list2, 2);
    list2 = insertEnd(list2, 4);
    list2 = insertEnd(list2, 6);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    struct Node* merged = mergeLists(list1, list2);

    printf("Merged List: ");
    display(merged);

    return 0;
}