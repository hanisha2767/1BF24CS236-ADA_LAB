int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int indegree[numCourses], queue[numCourses];
    int **g = malloc(numCourses * sizeof(int*));
    int size[numCourses];

    for(int i=0;i<numCourses;i++) {
        indegree[i]=0;
        size[i]=0;
        g[i]=malloc(numCourses * sizeof(int));
    }

    // Build graph
    for(int i=0;i<prerequisitesSize;i++) {

        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        g[b][size[b]++] = a;
        indegree[a]++;
    }

    int front=0, rear=0;

    for(int i=0;i<numCourses;i++)
        if(indegree[i]==0)
            queue[rear++] = i;

    int *ans = malloc(numCourses * sizeof(int));
    int k=0;

    while(front < rear) {

        int u = queue[front++];
        ans[k++] = u;

        for(int i=0;i<size[u];i++) {

            int v = g[u][i];
            indegree[v]--;

            if(indegree[v]==0)
                queue[rear++] = v;
        }
    }

    if(k != numCourses) {
        *returnSize = 0;
        return malloc(0);
    }

    *returnSize = numCourses;
    return ans;
}
