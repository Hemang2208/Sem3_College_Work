#include <stdio.h>

#define MAX 10

// Edge structure
struct Edge
{
    int u, v, weight;
};

// Find function (with path compression)
int find(int parent[], int i)
{
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

// Union function
void unionSet(int parent[], int u, int v)
{
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    parent[rootU] = rootV;
}

// Sort edges by weight (simple bubble sort)
void sortEdges(struct Edge edges[], int e)
{
    struct Edge temp;
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal Algorithm
void kruskal(struct Edge edges[], int V, int E)
{
    int parent[MAX];
    struct Edge result[MAX];
    int count = 0;

    // Initialize disjoint sets
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges
    sortEdges(edges, E);

    // Pick smallest edges
    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        // Check for cycle
        if (find(parent, u) != find(parent, v))
        {
            result[count++] = edges[i];
            unionSet(parent, u, v);
        }
    }

    // Print MST
    printf("Edges in MST:\n");
    int totalCost = 0;
    for (int i = 0; i < count; i++)
    {
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);
        totalCost += result[i].weight;
    }

    printf("Total cost = %d\n", totalCost);
}

// Main Function
int main()
{
    int V = 4; // vertices
    int E = 5; // edges

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    kruskal(edges, V, E);

    return 0;
}