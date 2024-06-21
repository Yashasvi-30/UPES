//preprocessor directives
#include <stdio.h>//for input output
#include <stdlib.h>// for dynamic allocation

int maxelement(int a, int b) //to find the maximum element of the two 
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() 
{
    int num;
    printf("Enter the number of objects: ");
    scanf("%d", &num);

    int profit[num + 1];
    int m;
    int wt[num + 1];

    printf("Enter the knapsack weight: ");
    scanf("%d", &m);

    int k[num + 1][m + 1];

    printf("Enter the profits and weights of the objects:\n");
    profit[0] = 0;
    wt[0] = 0;

    for (int i = 1; i < num + 1; i++) {
        printf("Enter weight of object %d: ", i);
        scanf("%d", &wt[i]);

        printf("Enter the profit of object %d: ", i);
        scanf("%d", &profit[i]);
    }

    for (int i = 0; i <= num; i++) {
        for (int w = 0; w <= m; w++) {
            if (i == 0 || w == 0) {
                k[i][w] = 0;
            } else if (wt[i] <= w) {
                k[i][w] = maxelement(k[i - 1][w], profit[i] + k[i - 1][w - wt[i]]);
            } else {
                k[i][w] = k[i - 1][w];
            }
        }
    }

    printf("Maximum profit: %d\n", k[num][m]);


    return 0;
}
