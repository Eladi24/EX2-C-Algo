#include <stdio.h>
#include "my_mat.h"



int main() {
    char choise;
    do {
        //printf("Please enter your choise: ");
        scanf("%c", &choise);

        switch (choise)
        {
        case 'A':
            createAdjMatrix();
            break;
            
        case 'B':
            isPath();
            break;

        case 'C':
            shortestPath();
            break;

        case 'D':
            break;

        default:
            
        }
    } 
    while (choise != 'D' && choise != EOF); 
    
    return 0;
    
}



