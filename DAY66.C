#include <stdio.h>
#include <stdbool.h>

bool dfs(int node, int V, int adj[V][V], bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, V, adj, visited, recStack))
                    return true;
            } else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[node] = false;
    return false;
}

int hasCycle(int V, int adj[V][V]) {
    bool visited[V], recStack[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, visited, recStack))
                return 1;
        }
    }

    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int adj[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    if (hasCycle(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}