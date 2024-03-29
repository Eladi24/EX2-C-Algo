#include <stdio.h>
#include "my_mat.h"

// Define maximum number of vertices in the graph
#define MAX_VERTICES 10
// Define maximum number of items in knapsack
#define MAX_ITEMS 5
// Define maximum weight of knapsack
#define MAX_WEIGHT 20
// Define maximum number of chars in item name
#define Max_Char 21
// An array to store the items
char stringsItems[MAX_ITEMS][Max_Char];
// An array to store items values
int values[MAX_ITEMS];
// An array to store items weights
int weights[MAX_ITEMS];
// An array to store selected item in knapsack
int selected_bool[MAX_ITEMS];
// An adjMatrix reprisenting the graph
int adjMatrix[MAX_VERTICES][MAX_VERTICES];

void createAdjMatrix()
{

    for (int i = 0; i < MAX_VERTICES; i++)
    {

        for (int j = 0; j < MAX_VERTICES; j++)
        {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    floydWarshall();
}

void floydWarshall()
{

    int i, j, k;
    /* Add all vertices one by one to
      the set of intermediate vertices.
       */
    for (k = 0; k < MAX_VERTICES; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < MAX_VERTICES; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < MAX_VERTICES; j++)
            {
                if (i != j && adjMatrix[i][j] == 0 && adjMatrix[i][k] != 0 && adjMatrix[k][j] != 0)
                {
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                }
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (adjMatrix[i][j] != 0 && adjMatrix[i][k] != 0 && adjMatrix[k][j] != 0)
                {
                    if (adjMatrix[i][k] + adjMatrix[k][j] < adjMatrix[i][j])
                    {
                        adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                    }
                }
            }
        }
    }
}

void isPath()
{

    int i, j;
    
    scanf("%d %d", &i, &j);
    
    if (adjMatrix[i][j] <= 0)
    {

        printf("False\n");
    }
    else
    {
        printf("True\n");
    }
}

void shortestPath()
{
    int i, j;
    
    scanf("%d %d", &i, &j);
    
    if (adjMatrix[i][j] > 0)
    {
        printf("%d\n", adjMatrix[i][j]);
    }

    else
    {
        printf("-1\n");
    }
}

void init()
{

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        
        scanf("%20s %d %d", stringsItems[i], &values[i], &weights[i]);

    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int selectItems(int weights[], int values[], int selected_bool[])
{
    int n = MAX_ITEMS;
    
    int W = MAX_WEIGHT;

    int K[n + 1][W + 1];
    int i, w;

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // store the result of Knapsack
    int res = K[n][W];

    w = W;
    for (i = n; i > 0 && res > 0; i--)
    {

        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if (res == K[i - 1][w])
            continue;
        else
        {

            // This item is included.
            selected_bool[i - 1] = 1;

            // Since this weight is included its
            // value is deducted
            res = res - values[i - 1];
            w = w - weights[i - 1];
        }
    }
    return K[n][W];
}

void printResult()
{
    init();
    printf("Maximum profit: %d\n", selectItems(weights, values, selected_bool));
    printf("Selected items:");
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (selected_bool[i] == 1)
        {
            printf(" %s", stringsItems[i]);
        }
    }
}
