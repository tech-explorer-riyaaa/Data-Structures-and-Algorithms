#include <iostream>
#include <cmath>
using namespace std;

// h >= 0
int balancedBTs(int h) {
    if (h <= 1) {
        return 1;  
    }
    int mod = (int)(pow(10, 9)) + 7;
    // power func returns the answer as double
    // typecast this to integer
    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2*(long)(x)*y) % mod);
    int ans = (temp1 + temp2) % mod; 

    // int ans = (x*x % mod + 2*x*y % mod) % mod;
    // no intermediate calc should go out of range.
    return ans;
}

int main() {
    int h;
    cin >> h;
    cout << balancedBTs(h) << endl;
    // still not giving correct answer    
}