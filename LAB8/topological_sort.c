#include <stdio.h>

#define MAX 10

int main() {
    int adj[MAX][MAX], indegree[MAX] = {0};
    int n, i, j, count = 0;
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Calculate indegree
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    printf("Topological Ordering:\n");

    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {

            // Select vertex with indegree 0 and not visited
            if(indegree[i] == 0 && visited[i] == 0) {
                found = 1;

                printf("%d ", i);

                visited[i] = 1;
                count++;

                // Remove outgoing edges
                for(j = 0; j < n; j++) {
                    if(adj[i][j] == 1)
                        indegree[j]--;
                }
            }
        }
        if(found == 0) {
           printf("\nCycle detected!\n");
           break;
        }
    }

    return 0;
}
