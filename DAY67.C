#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], stack[MAX];
int n, top = -1;

void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    stack[++top] = v; // push after visiting neighbors
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    // Call DFS for all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print Topological Order
    printf("Topological Sort: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}