#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

// BRUTE FORCE APPROACH

int minCostPath(int **input, int m, int n, int i, int j) {
    // brute force approach
     
    // base case
    // problem ko break kr krke bilkul last step p phoch jaaye/trivial case p phoch jaaye
    if(i == m - 1 && j == n - 1) {
        return input[i][j];
    }

    if(i >= m || j >= n) {
        return INT_MAX;
    }

    // recursive calls
    int x = minCostPath(input, m, n, i, j + 1);
    int y = minCostPath(input, m, n, i + 1, j + 1);
    int z = minCostPath(input, m, n, i + 1, j);

    // small calculation
    int ans = min(x, min(y, z)) + input[i][j];
    return ans;
}

int minCostPath(int **input, int m, int n) {
    return minCostPath(input, m, n, 0, 0);
}

// MEMOIZATION APPROACH

int minCostPath_mem(int **input, int** output, int m, int n, int i, int j) {
    // in memoization saath mei ek output var pass krna pdta hai jinme hum apne answer ko save kr rhe honge
    // brute force se kaafi similar hoga toh hum use hi copy kr lenge
    // only 2 extra steps

    // base case
    // problem ko break kr krke bilkul last step p phoch jaaye/trivial case p phoch jaaye
    if(i == m - 1 && j == n - 1) {
        return input[i][j];
    }

    if(i >= m || j >= n) {
        return INT_MAX;
    }

    // extra step in memoization
    // check if answer already exists
    if(output[i][j] != -1) {
        return output[i][j];
    }

    // recursive calls
    int x = minCostPath_mem(input, output, m, n, i, j + 1);
    int y = minCostPath_mem(input, output, m, n, i + 1, j + 1);
    int z = minCostPath_mem(input, output, m, n, i + 1, j);

    // small calculation
    int a = min(x, min(y, z)) + input[i][j];

    // saving the answer for future use
    output[i][j] = a;
    return a;
}

int minCostPath_mem(int **input, int m, int n, int i, int j) {
    int** output = new int*[m];
    for(int i = 0; i < m; i++){
        output[i] = new int[n];
        for(int j = 0; j < n; j++) {
            output[i][j] = -1;
        }
    }

    return minCostPath_mem(input, output, m, n, i, j);
}

// DYNAMIC PROGRAMMING APPROACH

int minCostPath_DP(int** input, int m, int n) {
    int **output = new int*[m];
    for(int i = 0; i < m; i++){
        output[i] = new int[n];
        // for(int j = 0; j < n; j++) {
        //     output[i][j] = -1;
        // } - no need of initialization
        // usi order mei access kr rhe h jis order mei fill kara hai
    }

    // fill the last destination cell
    output[m - 1][n - 1] = input[m - 1][n - 1];
    
    // fill last row - R to L manner
    for(int j = n - 2; j >= 0; j--) {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }

    // fill last column from bottom to top
    for(int i = m -2; i >= 0; i--) {
        output[i][n - 1] = output[i + 1][n - 1] + input[i][n - 1];
    }

    // fill remaining cells
    for(int i = m -2; i >= 0; i--) {
        for(int j = n - 2; j >= 0; j--) {
            output[i][j] = input[i][j] + min(output[i][j + 1], min(output[i + 1][j], output[i + 1][j + 1]));
        }
    }

    return output[0][0];

}

int main() {
    int m, n;
    cin >> m >> n;
    // created 2D array dynamically
    int **input = new int*[m];
    for(int i = 0; i < m; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    cout << minCostPath(input, m, n) << endl;
    cout << minCostPath_mem(input, m, n, 0, 0) << endl;
    cout << minCostPath_DP(input, m, n) << endl;
}

