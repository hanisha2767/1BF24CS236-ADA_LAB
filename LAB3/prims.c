#include <stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n, i, j, min, u = 0, v = 0;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int mincost = 0, edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in MST:\n");

    while(edges < n - 1) {
        min = INF;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d = %d\n", u, v, min);
        mincost += min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum cost = %d\n", mincost);

    return 0;
}
