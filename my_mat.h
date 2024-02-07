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

void init();

int selectItems(int weights[], int values[], int selected_bool[]);

int max(int a, int b);

void printResult();




















#endif