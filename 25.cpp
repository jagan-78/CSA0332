#include <stdio.h>
#define INF 9999
#define MAX 100

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX], visited[MAX] = {0}, i, j, min, u;

    for(i = 0; i < n; i++)
        dist[i] = INF;
    dist[start] = 0;

    for(i = 0; i < n - 1; i++) {
        min = INF;
        for(j = 0; j < n; j++)
            if(!visited[j] && dist[j] <= min) {
                min = dist[j];
                u = j;
            }

        visited[u] = 1;

        for(j = 0; j < n; j++)
            if(!visited[j] && graph[u][j] && dist[u] + graph[u][j] < dist[j])
                dist[j] = dist[u] + graph[u][j];
    }

    printf("Shortest distances from node %d:\n", start);
    for(i = 0; i < n; i++)
        printf("To %d = %d\n", i, dist[i]);
}

int main() {
    int graph[MAX][MAX], n, i, j, start;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    dijkstra(graph, n, start);
    return 0;
}

