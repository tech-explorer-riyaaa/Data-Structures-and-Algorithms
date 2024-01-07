#include <iostream>
using namespace std;

template <typename T>
class node {

    public :

    T data;
    node<T> *next;

    node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template <typename T> // ye line har class k liye alag alag mention krni pdegi
class stack {

    node<T> *head;
    int size; // number of elements present in stack

    public :

    stack() {
        // head = NULL
        // size = 0 // representing empty stack
        head = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(T element) {
        // create new node and insert it in the link
        // look if head NULL or not
        // update head
        // size++
        node<T> *newNode = new node<T>(element);
        newNode -> next = head;
        head = newNode;
        size++;
    }

    T pop() {
        // delete first element / node
        // deallocate node
        // if head == null
        // size--
        if (isEmpty()) { // otherwise segmentation fault in null -> or n .
            return 0;
        }
        T ans = head -> value;
        node<T> *temp = head; // temporary pointer
        head = head -> next; 
        delete temp;
        size--;
        return ans;
    }

    T top() {
        // check head null
        if(isEmpty()) {
            return 0;
        }
        return head -> value;
    }
};

int main() {
    stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.getSize() << endl;
    cout << s.isEmpty() << endl;
    
}