#include <iostream>
using namespace std;

class Bus {
    public:
    void print();
    // {
    //     // access x of truck
    // }
};

void test();

class Truck {
    private:
    int x;

    protected:
    int y;

    public: 
    int z;

    friend void Bus :: print();
    friend void test();
    // these two friend functions are not part of the class
    // friend functions do not have the access of this pointer
    // friend func ko kisi bhi access modifier k under daal skte hai - no effect
    // can put in public & private as well
    // because friend funcs are not member funcs

    void display() {
        cout << this -> x;
        cout << x;
        // this mei curernt object ka pointer hai
    }
};

void Bus :: print() {
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

void test() {
    // access private property of truck
    // global func ; not part of any class
    Truck t;
    t.x = 10;
    t.y = 20;
    cout << t.x << " " << t.y << endl;
}

int main() {
    Bus b;
    b.print();
    test();
}