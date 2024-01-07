#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int minStepsHelper(int n, int* ans) {
    // base case
    if(n <= 1) {
        return 0;
    }

    // check if output already exists
    if(ans[n] != -1) {
        return ans[n];
    }

    // calculate output
    int x = minStepsHelper(n - 1, ans);

    int y = INT_MAX, z = INT_MAX;
    if(n % 2 == 0) {
        y = minStepsHelper(n / 2, ans);
        // recursion iss answer ko khud save kr dega
        // no need for us to do
    }

    if(n % 3 == 0) {
        z = minStepsHelper(n / 3, ans);
    }

    int output = min(x, min(y, z)) + 1;

    // save output for future use
    ans[n] = output;

    return output;
}

int minSteps_2(int n) {
    // memoization approach
    int *ans = new int[n + 1];

    for(int i = 0; i <= n; i++) {
        ans[i] = -1;
    }

    return minStepsHelper(n ,ans);
}

int minSteps(int n) {
    // brute force recursive solution
    // base case
    if(n <= 1) {
        return 0;
    }

    // recursive call
    int x = minSteps(n - 1);

    int y = INT_MAX, z = INT_MAX;
    if(n % 2 == 0) {
        y = minSteps(n / 2);
    }

    if(n % 3 == 0) {
        z = minSteps(n / 3);
    }

    // calcualte final output
    int ans = min(x, min(y, z)) + 1; // inside cmath library
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << minSteps(n) << endl;
}