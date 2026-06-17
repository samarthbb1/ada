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
Bool isSafe(int row, int col) {
 Int I, j;
// Check this row on left side
 For (I = 0; I < col; i++)
 If (board[row][i]) return false;
 // Check upper diagonal on left side
 For (I = row, j = col; I >= 0 && j >= 0; i--, j--)
 If (board[i][j]) return false;
 // Check lower diagonal on left side
 For (I = row, j = col; j >= 0 && I < N; i++, j--)
 If (board[i][j]) return false;
 Return true;
}
// Recursive function to solve N-Queens
Bool solveNQUtil(int col) {
 // Base case: If all queens are placed, return true
 If (col >= N) {
 printSolution();
 return true;
 }
 Bool res = false;
 For (int I = 0; I < N; i++) {
If (isSafe(I, col)) {
 // Place queen
 Board[i][col] = 1;
 // Recur to place rest of the queens
 Res = solveNQUtil(col + 1) || res;
 // BACKTRACK: Remove queen from current cell
 Board[i][col] = 0;
 }
 }
 Return res;
}
int main() {
 printf("Enter the number of queens: ");
 scanf("%d", &N);
 if (!solveNQUtil(0)) {
 printf("Solution does not exist");
 }
 return 0;
}