#ifndef _MY_MAT_H_
#define _MY_MAT_H_

// Function to create Adjacency Matrix
void createAdjMatrix();

// Floyd-Warshall algorithm to get shortest path from each vertex to another
void floydWarshall();

// Return true if there's a path from i to j
void isPath();

// Returns the shortest path from i to j, if no path exists return -1
void shortestPath();

// Function that creates a list of 5 items and assign each one a value and weight
void init();

// Selects the max values items to put in Knapsack returns the max value
int selectItems(int weights[], int values[], int selected_bool[]);

// Returns max of (a,b)
int max(int a, int b);

// Function to print the selected items inside knapsack
void printResult();


#endif