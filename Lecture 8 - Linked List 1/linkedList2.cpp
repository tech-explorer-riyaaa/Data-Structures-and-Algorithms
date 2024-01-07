#include <iostream>
using namespace std;
#include "node.cpp"

void print(node *head) {
    node *temp = head;
    // don't lose the head. 
     while(temp != NULL) { // temp -> next != Null mei last node reh jayega
        cout << temp -> data << " ";
        temp = temp -> next;
     }
     cout << endl;
     temp = head;
     while(temp != NULL) { // temp -> next != Null mei last node reh jayega
        cout << temp -> data << " ";
        temp = temp -> next;
     }
     cout << endl;
}

void print2(node *head) { 
     while(head != NULL) { // head -> next != Null mei last node reh jayega
        cout << head -> data << " ";
        head = head -> next;
     }
     cout << endl;
    // copy bann rhi h isme head ki, hence, actual head lose nahi hoga ...
}

int main() {
     
    // statically

    node n1(1);
    node *head = &n1;

    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);

    // connecting
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head); // passing address of my first node

    print2(head);
    print2(head);
}