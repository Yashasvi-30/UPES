#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the Rod Cutting problem using dynamic programming
int rodCutting(int price[], int n) {
    int dp[n + 1];
    dp[0] = 0;

    // Build the dp table
    for (int i = 1; i <= n; i++) {
        int max_val = -1;
        for (int j = 0; j < i; j++) {
            max_val = max(max_val, price[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }

    // The result is stored in dp[n]
    return dp[n];
}

int main() {
    int n = 8;
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};

    int result = rodCutting(price, n);

    printf("Maximum value obtainable by cutting the rod = %d\n", result);

    return 0;
} 