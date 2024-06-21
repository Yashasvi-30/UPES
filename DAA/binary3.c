/*Given a string called TEXT with ‘n’ characters and another string called PATTERN with ‘m’ characters (m<=n) .
Write a program which implements brute force string matching 
to search for a given pattern in the text. If the pattern is present then find the position of first 
occurrences of Pattern in that Text.*/


#include <stdio.h>
#include <string.h>

// Brute-force string matching function
int bruteForceStringMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            // Pattern found at position i
            return i;
        }
    }

    // Pattern not found in the text
    return -1;
}

int main() {
    char text[100];
    char pattern[100];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern to search for: ");
    scanf("%s", pattern);

    int position = bruteForceStringMatch(text, pattern);

    if (position != -1) {
        printf("Pattern found at position %d in the text.\n", position);
    } else {
        printf("Pattern not found in the text.\n");
    }

    return 0;
}
