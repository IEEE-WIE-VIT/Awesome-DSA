#include <stdio.h>
#include <conio.h>
#define INFINITY 9999
#define MAX 10

int G[MAX][MAX];

void djikstra(int G[MAX][MAX], int n, int startNode){
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, minDistance, nextNode;

    for(int i = 0; i < n; i++){
        for(int j= 0; j < n; j++){
            if(G[i][j] == 0){
                cost[i][j] = INFINITY;
            }else{
                cost[i][j] = G[i][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        distance[i] = cost[startNode][i];
        pred[i] = startNode;
        visited[i] = 0;
    }

    distance[startNode] = 0;
    visited[startNode] = 1;
    count = 1;

    while(count < n - 1){
        minDistance = INFINITY;

        for(int i = 0; i<n; i++)
            if(distance[i] < minDistance && !visited[i]){
                minDistance = distance[i];
                nextNode = i;
            }
            visited[nextNode] = 1;

        for(int i = 0; i < n; i++)
            if(!visited[i])
                if(minDistance + cost[nextNode][i] < distance[i]){
                    distance[i] = minDistance + cost[nextNode][i];
                    pred[i] = nextNode;
                }
        count++;
    }

    for(int i = 0; i < n; i++){
        if(i != startNode){
            printf("\nDistance of node%d=%d",i,distance[i]);
            printf("\nPath=%d",i);

            int j = i;

            do{
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startNode);
        }
    }

}

int main(){
    int G[MAX][MAX],i,j,n,u;
    printf("Enter no. of vertices:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:\n");

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    
    printf("\nEnter the starting node:");
    scanf("%d",&u);
    djikstra(G,n,u);
    printf("\n\nPress any key to exit terminal: ");
    getch();
    return 0;

}