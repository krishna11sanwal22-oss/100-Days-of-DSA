#include <stdio.h>
#include <stdbool.h>

bool dfs(int node, int parent, int visited[], int adj[100][100], int n) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, visited, adj, n))
                    return true;
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);

    int adj[100][100] = {0};
    int visited[100] = {0};

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, n)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}