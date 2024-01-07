#include <iostream>
using namespace std;

void inplaceHeapSort(int input[], int n) {
    // Build the heap in input array
    for(int i = 1; i < n; i++) { // inserting elements in heap
        // up-heapify
        int childIndex = i; // element jisko uske parent se compare krna hai
        while (childIndex > 0) {
        int parentIndex = (childIndex - 1) / 2;
        if (input[childIndex] < input[parentIndex]) {
            int temp = input[childIndex];
            input[childIndex] = input[parentIndex];
            input[parentIndex] = temp;
        } else {
            // hum correct position p phoch chuke hai
            break;
        }
        childIndex = parentIndex;
        }
    } 
    // n times removeMin call to get it in decreasing order
    // Remove elements

    int size = n;
    while (size > 1) {
        int temp = input[0];
        input[0] = input[size - 1];
        input[size - 1] = temp;
        size--; 
        //unsorted array ka size ek kam
        // after swapping now we'll down-heapify
        // compare with its children

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while(leftChildIndex < size) {
            int minIndex = parentIndex;
            if(input[minIndex] > input[leftChildIndex]) {
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < size && input[rightChildIndex] < input[minIndex]) {
                minIndex = rightChildIndex;
            }
            // swap
            if(minIndex == parentIndex) {
                break;
            }
            int temp = input[minIndex];
            input[minIndex] = input[parentIndex];
            input[parentIndex] = temp;
            // assigning new set for loop
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}

int main() {
    int input[] = {5, 1, 2, 0, 8};
    inplaceHeapSort(input, 5);
    for(int i = 0; i < 5; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}
// decreasing order from minHeap 
// increasing order from maxHeap