#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[100][100];

    // Initialize graph
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;   // remove this line if graph is directed
    }

    int source;
    scanf("%d", &source);

    int dist[100];
    int visited[100] = {0};

    // Initialize distances
    for(int i = 1; i <= n; i++) {
        dist[i] = 100000;   // infinity
    }

    dist[source] = 0;

    for(int count = 1; count <= n; count++) {
        int min = 100000;
        int u = -1;

        // Find minimum distance vertex
        for(int i = 1; i <= n; i++) {
            if(visited[i] == 0 && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update distances
        for(int v = 1; v <= n; v++) {
            if(graph[u][v] != 0 && visited[v] == 0) {
                if(dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Print result
    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}