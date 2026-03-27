#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to count length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff;

    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    // Find difference
    if (len1 > len2) {
        diff = len1 - len2;
        for (int i = 0; i < diff; i++) {
            ptr1 = ptr1->next;
        }
    } else {
        diff = len2 - len1;
        for (int i = 0; i < diff; i++) {
            ptr2 = ptr2->next;
        }
    }

    // Traverse both
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1; // Intersection found
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL; // No intersection
}

// Display list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating common part
    struct Node* common = createNode(30);
    common->next = createNode(40);
    common->next->next = createNode(50);

    // First list: 10 -> 20 -> 30 -> 40 -> 50
    struct Node* head1 = createNode(10);
    head1->next = createNode(20);
    head1->next->next = common;

    // Second list: 15 -> 30 -> 40 -> 50
    struct Node* head2 = createNode(15);
    head2->next = common;

    printf("List 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL) {
        printf("Intersection Point: %d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }

    return 0;
}