#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findLCS(char* X, char* Y, int m, int n, int L[m+1][n+1], char D[m+1][n+1]) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
                D[i][j] = '\0';
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
                D[i][j] = 'D';
            } else {
                if (L[i - 1][j] >= L[i][j - 1]) {
                    L[i][j] = L[i - 1][j];
                    D[i][j] = 'U';
                } else {
                    L[i][j] = L[i][j - 1];
                    D[i][j] = 'L';
                }
            }
        }
    }
}

void printLCS(char* X, int m, int n, char D[m+1][n+1], int lcs_len) {
    char* lcs = (char*)malloc((lcs_len + 1) * sizeof(char));
    lcs[lcs_len] = '\0';

    int i = m, j = n;
    int index = lcs_len;

    while (i > 0 && j > 0) {
        if (D[i][j] == 'D') {
            lcs[--index] = X[i - 1];
            i--;
            j--;
        } else if (D[i][j] == 'U') {
            i--;
        } else {
            j--;
        }
    }
    printf("LCS: %s\n", lcs);
    free(lcs);
}

int main() {
    char X[] = "AGCCCTAAGGGCTACCTAGCTT";
    char Y[] = "GACAGCCTACAAGCGTTAGCTTG";

    int m = strlen(X);
    int n = strlen(Y);

    printf("Given DNA Sequences:\n");
    printf("X: %s (Length: %d)\n", X, m);
    printf("Y: %s (Length: %d)\n\n", Y, n);

    int L[m + 1][n + 1];
    char D[m + 1][n + 1];

    findLCS(X, Y, m, n, L, D);

    int lcs_length = L[m][n];
    printf("Length of LCS: %d\n", lcs_length);

    printLCS(X, m, n, D, lcs_length);

    return 0;
}