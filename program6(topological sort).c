#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top=-1;
int V;
void dfs(int v){
    visited[v]=1;
    for(int i=0;i<V;i++){
        if(adj[v][i]&&!visited[i]){
            dfs(i);
        }
    }
    stack[++top]=v;
}
void topologicalSort(){
    for(int i=0;i<V;i++)
        if(!visited[i])
            dfs(i);
    printf("Topological Order: ");
    while(top>=0)
        printf("%d ",stack[top--]);
    printf("\n");
}
int main(){
    int E,src,dest;
    printf("Enter number of vertices: ");
    scanf("%d",&V);
    printf("Enter number of edges: ");
    scanf("%d",&E);
    for(int i=0;i<E;i++){
        printf("Enter edge (from to): ");
        scanf("%d %d",&src,&dest);
        adj[src][dest]=1;
    }
    topologicalSort();
    return 0;
}


#OUTPUT:
Enter number of vertices: 5
Enter number of edges: 4
Enter edge (from to): 1 3
Enter edge (from to): 2 4
Enter edge (from to): 2 6 
Enter edge (from to): 2 3 
Topological Order: 2 4 1 3 0 
