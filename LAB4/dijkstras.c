#include <stdio.h>
#include <limits.h>

#define V 5

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print path
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

// Function to print solution
void printSolution(int dist[], int parent[]) {
    printf("Vertex\tDistance\tPath\n");

    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t", i, dist[i]);

        printf("0"); // source
        printPath(parent, i);

        printf("\n");
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u; // store parent
            }
        }
    }

    printSolution(dist, parent);
}

int main() {
    int graph[V][V];
    printf("enter elements in adjacency matrix:\n");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
           scanf("%d",&graph[i][j]);
        }
    }
    int src=0;
    dijkstra(graph,src);
}
