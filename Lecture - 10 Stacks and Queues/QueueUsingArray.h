template <typename T>
class QueueUsingArray {

    T* data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    QueueUsingArray(int s) {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    // insert element
    void enqueue(T element) {
        if (size == capacity) {
            cout << "Queue FULL." << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity; 
        if (firstIndex == -1) {
            firstIndex = 0;
        }
        size++; 
    }

    T front() {
        //if (firstIndex == -1)
        // getSize func
        // size variable
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity; // moving circularly
        size--;
        if(size == 0) { // iske bina bhi sb shi chlega but ye better h
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};