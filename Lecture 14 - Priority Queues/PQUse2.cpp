// K sorted array
#include <iostream>
using namespace std;
#include <queue>

void kSortedArray(int input[], int n, int k) {
    // same array mei changes
    // for 0th ele first k ele ka max lena hai
    // max heap chaiye
    priority_queue<int> pq;
    for(int i = 0; i < k; i++) {
        pq.push(input[i]);
    }
    int j = 0;
    for(int i = k; i < n; i++, j++) {
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
    }
    // n-k size ka array sort ho gya hoga
    // last k values apni sahi jagah nahi phoche honge
    while(!pq.empty()) {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}

int main() {
    int input[] = {10, 12, 6, 7, 9};
    int k = 3;
    kSortedArray(input, 5, k);
    for(int i = 0; i < 5; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}