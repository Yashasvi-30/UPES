#include <stdio.h>
#include <string.h>

int main() {
    char X[] = "Saurav";
    char Y[] = "Kartik";

    int m = strlen(X);
    int n = strlen(Y);

    int dp[m + 1][n + 1];

  
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    
    int length = dp[m][n];

    printf("Length of the longest common subsequence: %d\n", length);
  
    return 0;
}
