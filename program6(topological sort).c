#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];    // Visited array
int stack[MAX];      // Stack to store topological order
int top = -1;
int V;               // Number of vertices

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = v;  // Push to stack after visiting all descendants
}

void topologicalSort() {
    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i);

    printf("Topological Order: ");
    while (top >= 0)
        printf("%d ", stack[top--]);
    printf("\n");
}

int main() {
    int E, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        printf("Enter edge (from to): ");
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;  // Directed edge
    }

    topologicalSort();

    return 0;
}
