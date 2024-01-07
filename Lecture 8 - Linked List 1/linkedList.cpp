#include <iostream>
using namespace std;
#include "node.cpp"

int main() {

    // static creation of objects / nodes

    node n1(1);

    node *head = &n1; //  address node ka hai na

    node n2(2);

    n1.next = &n2;

    cout << head -> data << endl; // to access n1

    cout << n1.data << " " << n2.data << endl; 

    // dynamically
    node *n3 = new node(10);

    node *head2 = n3;
    node *n4 = new node(20);

    n3 -> next = n4;
}