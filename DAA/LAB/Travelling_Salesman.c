#include <stdio.h>

#define N 4
#define INF 99999

int minCost = INF;

// Function to find minimum
int min(int a, int b)
{
    return (a < b) ? a : b;
}

// TSP using Backtracking
void tsp(int graph[N][N], int visited[], int currPos, int count, int cost)
{

    // If all cities visited and return to start
    if (count == N && graph[currPos][0])
    {
        minCost = min(minCost, cost + graph[currPos][0]);
        return;
    }

    // Try all cities
    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && graph[currPos][i])
        {
            visited[i] = 1;

            tsp(graph, visited, i, count + 1, cost + graph[currPos][i]);

            // Backtrack
            visited[i] = 0;
        }
    }
}

// Main Function
int main()
{
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    int visited[N] = {0};

    visited[0] = 1; // start from city 0

    tsp(graph, visited, 0, 1, 0);

    printf("Minimum travelling cost = %d\n", minCost);

    return 0;
}

// Recursive TSP function

#include <stdio.h>

#define N 4
#define INF 99999

int minCost = INF;

// Utility function to find minimum
int min(int a, int b)
{
    return (a < b) ? a : b;
}

// Recursive TSP function
void tsp(int graph[N][N], int visited[], int currCity, int count, int cost)
{

    // Base case: all cities visited and return to start
    if (count == N && graph[currCity][0] > 0)
    {
        minCost = min(minCost, cost + graph[currCity][0]);
        return;
    }

    // Try visiting all unvisited cities
    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && graph[currCity][i] > 0)
        {

            visited[i] = 1; // mark as visited

            // Recursive call
            tsp(graph, visited, i, count + 1, cost + graph[currCity][i]);

            visited[i] = 0; // backtrack
        }
    }
}

// Main Function
int main()
{
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    int visited[N] = {0};

    visited[0] = 1; // start from city 0

    tsp(graph, visited, 0, 1, 0);

    printf("Minimum travelling cost = %d\n", minCost);

    return 0;
}