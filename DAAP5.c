#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int lcs_length(const char *X, const char *Y, int m, int n, int dp[m + 1][n + 1]) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } 
            else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else {
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

void print_lcs(const char *X, const char *Y, int m, int n, int dp[m + 1][n + 1], int lcs_len) {
    char *lcs_str = (char *)malloc((lcs_len + 1) * sizeof(char));
    if (lcs_str == NULL) {
        perror("Failed to allocate memory");
        return;
    }
    lcs_str[lcs_len] = '\0'; 

    int index = lcs_len;
    int i = m;
    int j = n;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str[index - 1] = X[i - 1]; 
            i--; 
            j--;
            index--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; 
        } 
        else {
            j--; 
        }
    }

    printf("LCS: %s\n", lcs_str);

    free(lcs_str);
}

int main() {
    const char X1[] = "AGGTAB";
    const char Y1[] = "GXTXAYB";
    int m1 = strlen(X1);
    int n1 = strlen(Y1);
    int dp1[m1 + 1][n1 + 1];

    printf("String X: %s\n", X1);
    printf("String Y: %s\n", Y1);

    int len1 = lcs_length(X1, Y1, m1, n1, dp1);
    printf("Length of LCS: %d\n", len1);
    print_lcs(X1, Y1, m1, n1, dp1, len1); 

    printf("\n");
    
    const char X2[] = "ABCDE";
    const char Y2[] = "ACE";
    int m2 = strlen(X2);
    int n2 = strlen(Y2);
    int dp2[m2 + 1][n2 + 1];

    printf("String X: %s\n", X2);
    printf("String Y: %s\n", Y2);
    
    int len2 = lcs_length(X2, Y2, m2, n2, dp2);
    printf("Length of LCS: %d\n", len2);
    print_lcs(X2, Y2, m2, n2, dp2, len2); 

    return 0;
}