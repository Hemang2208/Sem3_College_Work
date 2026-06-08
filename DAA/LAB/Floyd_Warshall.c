#include <stdio.h>

#define V 4
#define INF 99999

// Function to print the solution matrix
void printSolution(int dist[V][V]){
    printf("Shortest distance matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd-Warshall Algorithm
void floydWarshall(int graph[V][V]){
    int dist[V][V];

    // Initialize distance matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Main algorithm
    for (int k = 0; k < V; k++)
    { // Intermediate vertex
        for (int i = 0; i < V; i++)
        { // Source
            for (int j = 0; j < V; j++)
            { // Destination
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

// Main Function
int main()
{
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}};

    floydWarshall(graph);

    return 0;
}