#include <stdio.h>
#include "my_mat.h"

int main()
{
    char choise;
    do
    {
        
        scanf("%c", &choise);

        switch (choise)
        {
        case 'A':
        {
            createAdjMatrix();
            break;
        }
        case 'B':
        {
            isPath();
            break;
        }
        case 'C':
        {
            shortestPath();
            break;
        }
        }
    } while (choise != 'D' && choise != EOF);

    return 0;
}
