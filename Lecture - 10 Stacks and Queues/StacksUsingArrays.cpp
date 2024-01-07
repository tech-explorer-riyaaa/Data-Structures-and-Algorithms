#include <climits>
class StackUsingArray {

    int *data; // created pointer
    int nextIndex;
    int capacity;

    public : 

    // constructor
    StackUsingArray(int totalSize) {
        data = new int[totalSize]; // pointed the pointer to the array
        nextIndex = 0;
        capacity = totalSize;
    }

    // return the number of elements present in my stack
    int size() {
        return nextIndex;
    }

    // whether my stack is empty or not
    bool isEmpty() {
        /*
        if (nextIndex == 0) {
            return true;
        } else {
            return false;
        }
        */

       return nextIndex == 0; // prints 1 for true and 0 for false
    }

    // to insert an element in the stack
    void push(int element) {

        if (nextIndex == capacity) {
            cout << "Stack FULL" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // to delete the element
    int pop() {
        /* OR can use size func here
        if(nextIndex == 0) {
            cout << "Stack EMPTY." << endl;
            return;
        }
        */
       if (isEmpty()) {
        cout << "Stack EMPTY" << endl;
        return INT_MIN; // as an indication that outr stack is empty
       }
        nextIndex--;
        return data[nextIndex];
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack EMPTY" << endl;
            return INT_MIN; // as an indication that outr stack is empty
        }
        return data[nextIndex - 1];
    }

};