#include <vector>
using namespace std; // without this compiler didn't recognised vector
// If you are in a namespace, make sure you are either using the std:: namespace explicitly or have a using namespace std; statement in your code. This is necessary because vector is part of the std namespace. 

// header file
// 3 major functions - insert, remove and getMin
// isEmpty(), getSize() func
// Min priority queue
// max priority - min element
// CBT, HOP

// CBT is saved as array - not required a binary tree.
class PriorityQueue {
    vector<int> pq;

    public:
    // constructor
    PriorityQueue() {
        // to initilaise data members
    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    int getSize() {
        // number of elements present
        return pq.size();
    }

    int getMin() {
        if(isEmpty()){
            return 0; // pq is empty.
        }
        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0) {
        int parentIndex = (childIndex - 1) / 2;
        if (pq[childIndex] < pq[parentIndex]) {
            int temp = pq[childIndex];
            pq[childIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
        } else {
            // hum correct position p phoch chuke hai
            break;
        }
        childIndex = parentIndex;
        }
    }

    int removeMin() {
        if(isEmpty()) {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        // down-heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while(leftChildIndex < pq.size()) {
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex]) {
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex]) {
                minIndex = rightChildIndex;
            }
            // swap
            if(minIndex == parentIndex) {
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            // assigning new set for loop
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans; 
    }
};
