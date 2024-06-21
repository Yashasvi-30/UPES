#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(int W, int wt[], int val[], int n) {
    // Create a table to store solutions to subproblems
    int **K = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        K[i] = (int *)malloc((W + 1) * sizeof(int));
    }
 
    // Build table K[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Base case: If there are no items or the knapsack has no capacity
            if (i == 0 || w == 0)
                K[i][w] = 0;
            // If the weight of the current item is less than or equal to the remaining capacity
            else if (wt[i - 1] <= w)
                // Choose the maximum value between including and excluding the current item
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                // If the current item's weight exceeds the remaining capacity, exclude it
                K[i][w] = K[i - 1][w];
        }
    }

    // The maximum value that can be obtained is stored in K[n][W]
    int result = K[n][W];

    // Free dynamically allocated memory
    for (int i = 0; i <= n; i++) {
        free(K[i]);
    }
    free(K);

    return result;
}

// Function to take user input for values, weights, and knapsack capacity
void takeUserInput(int *n, int **val, int **wt, int *W) {
    printf("Enter the number of items: ");
    scanf("%d", n);

    *val = (int *)malloc(*n * sizeof(int));
    *wt = (int *)malloc(*n * sizeof(int));

    printf("Enter the values of the items:\n");
    for (int i = 0; i < *n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &(*val)[i]);
    }

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < *n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &(*wt)[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", W);
}

// Function to print the result
void printResult(int result) {
    printf("Maximum value: %d\n", result);
}

int main() {
    int n, *val, *wt, W;

    // Take user input
    takeUserInput(&n, &val, &wt, &W);

    // Solve the knapsack problem and get the result
    int result = knapsack(W, wt, val, n);

    // Print the result
    printResult(result);

    // Free dynamically allocated memory
    free(val);
    free(wt);

    return 0;
}
