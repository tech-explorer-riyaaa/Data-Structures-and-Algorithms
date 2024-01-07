#include <climits>
template <typename T> 
class StackUsingDArray {

    T *data; // created Ter
    int nextIndex;
    int capacity;

    public : 

    // constructor
    StackUsingDArray() {
        data = new T[4]; // pointed the pointer to the array
        nextIndex = 0;
        capacity = 4;
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
    void push(T element) {

        if (nextIndex == capacity) {
            T *newData = new T[2 * capacity];
            for(int i = 0; i < capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    // to delete the element
    T pop() {
        /* OR can use size func here
        if(nextIndex == 0) {
            cout << "Stack EMPTY." << endl;
            return;
        }
        */
       if (isEmpty()) {
        cout << "Stack EMPTY" << endl;
        // return INT_MIN; // as an indication that outr stack is empty
        return 0; // 0 ia a standard value - can be used for any datatype
       }
        nextIndex--;
        return data[nextIndex];
    }

    T top() {
        if (isEmpty()) {
            cout << "Stack EMPTY" << endl;
            // return INT_MIN; // as an indication that outr stack is empty
            return 0;
        }
        return data[nextIndex - 1];
    }

};

// can't have main function