#include <stdio.h>
#include <limits.h>

#define MAX 10
int tsp(int graph[MAX][MAX], int visited[], int pos, int n, int count, int cost, int start) {
    if (count == n && graph[pos][start])
        return cost + graph[pos][start];

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = 1;
            int temp = tsp(graph, visited, i, n, count + 1, cost + graph[pos][i], start);
            if (temp < ans) ans = temp;
            visited[i] = 0;
        }
    }
    return ans;
}

int main() {
    int graph[MAX][MAX], visited[MAX] = {0}, n;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix (0 if no path):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    visited[0] = 1; // start from city 0
    int result = tsp(graph, visited, 0, n, 1, 0, 0);
    printf("Minimum cost of travel: %d\n", result);

    return 0;
}

