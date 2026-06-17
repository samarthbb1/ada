#include <stdio.h>

#define MAX 100

// Function to perform topological sort using Kahn's algorithm
void topologicalSort(int n, int graph[MAX][MAX]) {
    int inDegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topoOrder[MAX], index = 0;

    // Compute in-degree of each vertex
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (graph[i][j] != 0)
                inDegree[j]++;

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            queue[rear++] = i;

    // Process vertices
    while (front < rear) {
        int u = queue[front++];
        topoOrder[index++] = u;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0) {
                inDegree[v]--;
                if (inDegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    // Check if topological ordering is possible (no cycle)
    if (index != n) {
        printf("Graph has a cycle, topological ordering not possible.\n");
        return;
    }

    printf("Topological Ordering: ");
    for (int i = 0; i < n; i++)
        printf("%d ", topoOrder[i]);
    printf("\n");
}

int main() {
    int n = 6; // number of vertices
    int graph[MAX][MAX] = {0};

    // Define edges (directed)
    graph[5][2] = 1;
    graph[5][0] = 1;
    graph[4][0] = 1;
    graph[4][1] = 1;
    graph[2][3] = 1;
    graph[3][1] = 1;

    topologicalSort(n, graph);

    return 0;
}