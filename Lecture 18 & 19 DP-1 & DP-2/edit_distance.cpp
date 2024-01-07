#include <iostream>
#include <cmath>
using namespace std;

// BRUTE FORCE APPROACH
int editDistance(string s, string t) {
    // base case
    if(s.size() == 0 || t.size() == 0) {
        return max(s.size(), t.size());
        // utne insert operations in empty string
    }

    // recursive calls
    if(s[0] == t[0]) {
        return editDistance(s.substr(1), t.substr(1));
    } else {
        // insert
        int x = editDistance(s.substr(1), t) + 1;   
        // delete
        int y = editDistance(s, t.substr(1)) + 1;
        // replace
        int z = editDistance(s.substr(1), t.substr(1)) + 1;

        return min(x, min(y, z));

    }
}

// MEMOIZATION
int editDistance_mem(string s, string t, int** output) {
    // copy paste recursion wala code
    // add two steps

    int m = s.size();
    int n = t.size();

    // base case
    if(s.size() == 0 || t.size() == 0) {
        return max(s.size(), t.size());
        // utne insert operations in empty string
    }

    // check if ans already exists
    if(output[m][n] != -1) {
        return output[m][n];
    }

    // recursive calls
    int ans;
    if(s[0] == t[0]) {
        ans = editDistance_mem(s.substr(1), t.substr(1), output);
    } else {
        // insert
        int x = editDistance_mem(s.substr(1), t, output) + 1;   
        // delete
        int y = editDistance_mem(s, t.substr(1), output) + 1;
        // replace
        int z = editDistance_mem(s.substr(1), t.substr(1), output) + 1;

        ans =  min(x, min(y, z));
    }

    // save the ans
    output[m][n] = ans;

    // return the ans
    return ans;
}

int editDistance_mem(string s, string t) {
    int m = s.size();
    int n = t.size();
    int **ans = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        ans[i] = new int[n + 1];
        for(int j = 0; j <= n; j++) {
            ans[i][j] = -1;
        }
    }
    return editDistance_mem(s, t, ans);
}

// Dynamic Programming
int editDistance_DP(string s, string t) {
    int m = s.size();
    int n = t.size();
    int **output = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        output[i] = new int[n + 1];
    }

    // fill first row
    for(int j = 0; j <= n; j++) {
        output[0][j] = j;
    }

    // fill first column
    for(int i = 1; i <= m; i++) {
        output[i][0] = i;
    }

    // remaining array
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[m - i] == t[n - j]) {
                // first charcter inn index p milega like in LCS
                // aage se characters remove ho rhe hai
                output[i][j] = output[i - 1][j - 1];
            } else {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];

                output[i][j] = min(a, min(b, c)) + 1  ;
                // first char match nahi kara
                // ek operation hum khud kr rhe hai
            }
        }
    }
    return output[m][n];
}

int main() {
    string s = "abcdfdt";
    string t = "afdf";

    cout << editDistance_mem(s, t) << endl;
    cout << editDistance_DP(s, t) << endl;
    cout << editDistance(s, t) << endl; //  time complexity badi harab hai badi string p try karo


}