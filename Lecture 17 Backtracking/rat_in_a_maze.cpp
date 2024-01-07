// following order - up, down, left, right
// #inlcude<bits/stc++.h>
// in printing all paths - we don't think about time complexity
// saare paths print krne hai - go for backtracking

#include <iostream>
using namespace std;

void printSolution(int** solution, int n) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    // cout << endl;
}

void mazeHelp(int maze[][20], int n, int** solution, int x, int y) {

    if (x == n - 1 && y == n - 1) {
        solution[x][y] = 1;
        printSolution(solution, n);
        solution[x][y] = 0; // iske bina bhi chal jayega
        return;
    }
    if(x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || maze[x][y] == 1) {
        return;
    }
    solution[x][y] = 1;
    mazeHelp(maze, n, solution, x - 1, y); // up
    mazeHelp(maze, n, solution, x + 1, y); // down
    mazeHelp(maze, n, solution, x, y - 1); // left
    mazeHelp(maze, n, solution, x, y + 1); // right
    solution[x][y] = 0;
}

void ratInMaze(int maze[][20], int n) {
    // int** solution = new int*[n];
    // for(int i = 0; i < n; i++) {
    //     solution[i] = new int*[n];
    // } // dynamic allocation
    // // or we can use global array as in n queen

    // mazeHelp(maze, n, solution, 0, 0);
    // // n - rows & cols in rows
    // // starting point - x, y = 0, 0

    int** solution = new int*[n];
    for(int i=0;i<n;i++){
        solution[i] = new int[n];
    }
    // Initialization of solution 2D array with 0
    for(int i=0; i<n; i++){
        for(int j = 0; j < n; j++) {
            solution[i][j] = 0;
        }
        // memset(solution[i], 0, n*sizeof(int));
    }
    mazeHelp(maze,n,solution,0,0);

}

int main() {

    return 0;

}