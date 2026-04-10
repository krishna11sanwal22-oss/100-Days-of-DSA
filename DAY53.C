#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct QNode {
    Node* node;
    int hd;
} QNode;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void verticalOrder(Node* root, int n) {
    if (!root) return;

    QNode* queue = (QNode*)malloc(n * sizeof(QNode));
    int front = 0, rear = 0;

    int *hd = (int*)malloc(n * sizeof(int));
    int min = 0, max = 0;

    queue[rear++] = (QNode){root, 0};

    Node** nodes = (Node**)malloc(n * sizeof(Node*));
    int count = 0;

    while (front < rear) {
        QNode temp = queue[front++];
        nodes[count] = temp.node;
        hd[count] = temp.hd;

        if (temp.hd < min) min = temp.hd;
        if (temp.hd > max) max = temp.hd;

        count++;

        if (temp.node->left)
            queue[rear++] = (QNode){temp.node->left, temp.hd - 1};
        if (temp.node->right)
            queue[rear++] = (QNode){temp.node->right, temp.hd + 1};
    }

    for (int line = min; line <= max; line++) {
        for (int i = 0; i < count; i++) {
            if (hd[i] == line) {
                printf("%d ", nodes[i]->data);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    verticalOrder(root, n);

    return 0;
}