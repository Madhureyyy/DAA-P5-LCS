#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void findAndPrintLRS(char* S) {
    int n = strlen(S);
    
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (S[i - 1] == S[j - 1] && i != j) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int lrs_length = dp[n][n];
    printf("Length of Longest Repeating Subsequence: %d\n", lrs_length);

    char* lrs = (char*)malloc((lrs_length + 1) * sizeof(char));
    lrs[lrs_length] = '\0';
    
    int i = n, j = n;
    int index = lrs_length;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j - 1] + 1) {
            lrs[--index] = S[i - 1];
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j]) {
            i--;
        }
        else {
            j--;
        }
    }
    
    printf("LRS is: %s\n", lrs);
    free(lrs);
}


int main() {
    char S1[] = "AABCBDC";
    printf("Input String 1: %s\n", S1);
    findAndPrintLRS(S1);
    
    printf("\n");

    char S2[] = "ATACTCGGA";
    printf("Input String 2: %s\n", S2);
    findAndPrintLRS(S2);

    return 0;
}