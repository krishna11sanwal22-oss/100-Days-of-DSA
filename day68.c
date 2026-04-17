#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], indegree[MAX], queue[MAX];
int n;

int main() {
    int edges, u, v;
    int front = 0, rear = -1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
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
        indegree[v]++;  // increase indegree
    }

    // Push vertices with indegree 0 into queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    printf("Topological Sort: ");

    while (front <= rear) {
        int node = queue[front++];
        printf("%d ", node);

        // Reduce indegree of neighbors
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    return 0;
}