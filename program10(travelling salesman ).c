#include <stdio.h>
#include <limits.h>
#define MAX 16
int dist[MAX][MAX],visited[MAX],n;
int tsp(int pos){
    visited[pos]=1;
    int nearest=-1,minDist=INT_MAX;
    for(int i=0;i<n;i++){
        if(!visited[i]&&dist[pos][i]<minDist){
            minDist=dist[pos][i];
            nearest=i;
        }
    }
    if(nearest==-1)return dist[pos][0];
    return minDist+tsp(nearest);
}
int main(){
    printf("Enter the number of cities: ");
    scanf("%d",&n);
    printf("Enter the distance matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&dist[i][j]);
        }
    }
    for(int i=0;i<n;i++)visited[i]=0;
    int result=tsp(0);
    printf("Minimum cost using greedy approach: %d\n",result);
    return 0;
}

//OUTPUT:
Enter the number of cities: 3
Enter the distance matrix:
1
2
3
4
5
6
7
8
9
Minimum cost using greedy approach: 15
