#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    return root;
}

int main() {
    int n, i, x, a, b;
    struct Node* root = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &a, &b);

    struct Node* result = LCA(root, a, b);

    if (result != NULL)
        printf("%d", result->data);

    return 0;
}