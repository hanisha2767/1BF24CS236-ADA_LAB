#include <stdio.h>
#define MAX 20

int parent[MAX];

int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int u, int v) {
    parent[u] = v;
}

int main() {
    int n, e, i, j;
    int u[MAX], v[MAX], w[MAX];
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    for(i = 0; i < n; i++)
        parent[i] = i;

    printf("Enter edges (u v weight):\n");
    for(i = 0; i < e; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

    for(i = 0; i < e - 1; i++) {
        for(j = i+1; j < e ; j++) {
            if(w[i] > w[j]) {
                int temp;

                temp = w[i]; w[i] = w[j]; w[j] = temp;
                temp = u[i]; u[i] = u[j]; u[j] = temp;
                temp = v[i]; v[i] = v[j]; v[j] = temp;
            }
        }
    }

    int mincost = 0, count = 0;

    printf("\nEdges in MST:\n");

    for(i = 0; i < e && count < n - 1; i++) {
        int pu = find(u[i]);
        int pv = find(v[i]);

        if(pu != pv) {
            printf("%d -> %d = %d\n", u[i], v[i], w[i]);
            mincost += w[i];
            unionSet(pu, pv);
            count++;
        }
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
