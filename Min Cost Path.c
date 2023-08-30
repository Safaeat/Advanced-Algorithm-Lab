#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int minCostPath(int **matrix, int rows, int cols) {
    int dp[rows][cols];

    dp[0][0] = matrix[0][0];

    for (int i = 1; i < rows; i++)
        dp[i][0] = dp[i - 1][0] + matrix[i][0];

    for (int j = 1; j < cols; j++)
        dp[0][j] = dp[0][j - 1] + matrix[0][j];

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[rows - 1][cols - 1];
}

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Input the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    printf("Enter your matrix values(Give blank space between numbers ): \n");
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int result = minCostPath(matrix, rows, cols);
    printf("Minimum cost path: %d\n", result);

    return 0;
}
