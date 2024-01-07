#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> removeDuplicates(int* a, int size) { // O(n)
    vector<int> output;
    unordered_map<int, bool> seen;
    for(int i = 0; i < size; i++) {
        // use count function
        if (seen.count(a[i]) > 0) {
            continue;
        }
        seen[a[i]] = true; // O(1)
        // this step would take log n time in normal map
        // so time complexity would have become nlogn
        output.push_back(a[i]);
    }
    return output;
}

int main() {
    int a[] = {1, 2, 3, 3, 2, 1, 4, 3, 6, 5, 5};
    vector<int> output = removeDuplicates(a, 11);
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    } cout << endl;
}