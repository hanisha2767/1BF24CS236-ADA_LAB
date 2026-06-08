#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int board[MAX], n;

// Function to check whether queen can be placed
int isSafe(int row, int col) {
    int i;

    for(i = 0; i < row; i++) {

        // Same column
        if(board[i] == col)
            return 0;

        // Same diagonal
        if(abs(board[i] - col) == abs(i - row))
            return 0;
    }

    return 1;
}

// Function to print solution
void printSolution() {
    int i, j;

    printf("\nSolution:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            if(board[i] == j)
                printf("Q ");
            else
                printf("- ");
        }
        printf("\n");
    }
}

// Backtracking function
void solveNQueens(int row) {
    int col;

    if(row == n) {
        printSolution();
        return;
    }

    for(col = 0; col < n; col++) {

        if(isSafe(row, col)) {

            board[row] = col;

            solveNQueens(row + 1);
        }
    }
}

int main() {

    printf("Enter number of queens: ");
    scanf("%d", &n);

    solveNQueens(0);

    return 0;
}
