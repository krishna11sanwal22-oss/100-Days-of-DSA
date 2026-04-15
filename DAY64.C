#include <stdio.h>

int adj[100][100], visited[100], queue[100];
int front = -1, rear = -1, n;

void enqueue(int x) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void BFS(int s) {
    int i;
    enqueue(s);
    visited[s] = 1;

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
        visited[i] = 0;
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    printf("BFS Traversal: ");
    BFS(s);

    return 0;
}