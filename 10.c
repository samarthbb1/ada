#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int board[MAX][MAX];
int N;

// Function to print the board configuration
void printSolution() {
    static int count = 1;
    printf("\nSolution %d:\n", count++);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

// Check if it’s safe to place a queen at board[row][col]
bool isSafe(int row, int col) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function
bool solveNQUtil(int col) {
    if (col >= N) {
        printSolution();
        return true;
    }

    bool res = false;

    for (int i = 0; i < N; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 1;

            res = solveNQUtil(col + 1) || res;

            // Backtrack
            board[i][col] = 0;
        }
    }

    return res;
}

int main() {
    printf("Enter the number of queens: ");
    scanf("%d", &N);

    if (!solveNQUtil(0)) {
        printf("Solution does not exist\n");
    }

    return 0;
}
