#include <iostream>
using namespace std;

int fibo(int n) {
    // recursive function
    // brute force without any optimisation
    if(n <= 1) {
        return n;
    }
    int a = fibo(n - 1);
    int b = fibo(n - 2);
    return a + b;
}
 
int fibo_helper(int n, int* ans) {
    // memoization approach
    // top-down approach
    if(n <= 1) {
        return n;
    }

    // check if output already exists
    if(ans[n] != -1) {
        return ans[n];
    }

    int a = fibo_helper(n - 1, ans);
    int b = fibo_helper(n - 2, ans);

    // save the output for future use
    ans[n] = a + b;

    // return the final output
    return ans[n];
}

int fibo_2(int n) {
    int *ans = new int[n + 1];
    // we will solve it recursively.
    for(int i = 0; i < n; i++) {
        ans[i] = -1;
    }
    return fibo_helper(n, ans);
}

int fibo_3(int n) {
    // iteratively not recursively
    // this is dynamic programming
    // bottom up approach
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;

    for(int i = 2; i <= n; i++) {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n) << endl;
}