class dynamicArray {
    int *data;
    int nextIndex;
    int capacity; // total size

    public :

    dynamicArray() {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    // copy constructor
    dynamicArray(dynamicArray const &d) {
        /*
        in-built - shallow copy
        this -> data = d.data;
        this -> nextIndex -> d.nextIndex;
        this -> capacity -> d.capacity;
        */

       // we're not blindly copying purane wale array ka address
       // Deep Copy
       this -> data = new int[d.capacity];
       for(int i = 0; i < d.nextIndex; i++) {
            this -> data[i] = d.data[i];
       }
       this -> nextIndex = d.nextIndex;
       this -> capacity = d.capacity;
    }

    // operator overloading
    // copy assignment operator
    void operator=(dynamicArray const &d) {
        this -> data = new int[d.capacity];
        for(int i = 0; i < d.nextIndex; i++) {
            this -> data[i] = d.data[i];
        }
       this -> nextIndex = d.nextIndex;
       this -> capacity = d.capacity;
    }

    void add(int element) {
        if (nextIndex == capacity) {
            int *newData = new int[2 * capacity];
            for(int i = 0; i < capacity; i++) {
                newData[i] = data[i]; // newData is local var, iska scope func k bahar jaate hi finish ho jayega.
            }
            delete data; // deleting array
            data = newData; // poiting data to newData
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int get (int i) const {
        if(i < nextIndex){
            return data[i];
        } else {
            return -1;
        }
    }

    void add(int i, int element) { // placing element at a particular index
        if(i < nextIndex){
            data[i] = element;
        } else if (i == nextIndex) {
            add(element);
        } else {
            cout << element << " not added" << endl;
            return;
        }
    }

    void print() const {
        for(int i = 0; i < nextIndex; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};