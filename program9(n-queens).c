#include <stdio.h>
#include <stdbool.h>

#define N 8  // You can change N to any other number for different sizes of the board

// Function to print the chessboard solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

// A utility function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Backtracking function to solve the N Queens problem
bool solveNQueens(int board[N][N], int row) {
    // If all queens are placed
    if (row >= N) {
        return true;
    }

    // Consider this row and try placing this queen in all columns
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            // Place the queen in the current column
            board[row][col] = 1;

            // Recur to place the next queen
            if (solveNQueens(board, row + 1)) {
                return true;
            }

            // If placing queen in the current column doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int board[N][N] = {0};  // Initialize the board with 0 (no queens placed)

    // Solve the N Queens problem
    if (solveNQueens(board, 0)) {
        printSolution(board);
    } else {
        printf("Solution does not exist\n");
    }

    return 0;
}
