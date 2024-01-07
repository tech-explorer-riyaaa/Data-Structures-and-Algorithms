// #include<bits/stc++.h>
#include <iostream>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int column) {

    // same column
    for(int i = row - 1; i >= 0 ; i--) {
        if(board[i][column] == 1) {
            return false;
        }
    }

    // upper left diagonal
    for(int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1) {
            return false;
        }
    }

    // upper right diagonal
    for(int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void nQueenHelper(int n, int row) {
    // current row is row.
    if (row == n) {
        // we have reached some solution
        // print the board matrix
        // return

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    // place at all possible positions and move to smaller problem
    for(int j = 0; j < n; j++) {
        if (isPossible(n, row, j)) { // n - total rows
            board[row][j] = 1;
            nQueenHelper(n, row + 1);
            board[row][j] = 0;
        }
    }
    return;
}

void placeNQueens(int n) {
    // print all possible configurations in 1D
    // 1 <= N <= 10
    //memset(board, 0, 11*11*sizeOf(int));
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < 11; j++) {
            board[1][j] = 0;
        }
    }

    nQueenHelper(n, 0);
}

int main() {

    placeNQueens(4);
    return 0;

}
