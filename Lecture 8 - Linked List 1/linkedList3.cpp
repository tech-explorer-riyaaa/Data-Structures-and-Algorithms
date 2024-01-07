#include <iostream>
using namespace std;
#include "node.cpp"

class pair2 {
    public :

    node *head;
    node *tail;

};
// naming it pair was giving error

node* reverseLL_3(node *head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }

    node *smallAns = reverseLL_3(head -> next);
    node *tail = head -> next;
    tail -> next = head;
    head -> next = NULL;
    return smallAns;
}

pair2 reverseLL_2(node *head) {
     if (head == NULL || head -> next == NULL) {
        pair2 ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    pair2 smallAns = reverseLL_2(head -> next);
    smallAns.tail -> next = head;
    head -> next = NULL;
    pair2 ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

node* reverseLLBetter(node *head) {
    return reverseLL_2(head).head;
}

node* takeInput() {
    int data;
    cin >> data;
    node *head = NULL;
    while (data != -1) {
        // node n(data); // iska scope ek iteration h bas - aage badhte jaa rhe h nodes del hoti jaa rhi h
        // hence we'll use dynamic allocation - use explicitly del krwana pdta hai
        node *newNode = new node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            node *temp = head;
            while (temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
        cin >> data;
    }
    return head;
}

node* reverseLL(node *head) {
    if (head == NULL || head -> next == NULL) {
        return head;
    }

    node *smallAns = reverseLL(head -> next);
    node *temp = smallAns;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next  = head;
    head -> next = NULL;
    return smallAns;
}




node* takeInputBetter() {
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1) {
        node *newNode = new node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = tail -> next;
            // OR 
            // tail = newNode;
        }
        cin >> data;
    }
    return head;
}

node* insertNode(node *head, int i, int data) {
    node *newNode = new node(data);
    int count = 0;
    node *temp = head;

    if (i == 0) {
        newNode -> next = head;
        head = newNode;
        return head;
    }

    while (temp != NULL && count < i - 1) {
        temp = temp -> next;
        count++;
    }
    // node *a = temp -> next;
    // temp -> next = newNode;
    // newNode -> next = a;
    if (temp != NULL){
        newNode -> next = temp -> next;
        temp -> next = newNode;
    } 
    return head;
}

void print(node *head) { 
     while(head != NULL) { // head -> next != Null mei last node reh jayega
        cout << head -> data << " ";
        head = head -> next;
     }
     cout << endl;
    // copy bann rhi h isme head ki, hence, actual head lose nahi hoga ...
}

int main() {

    /*
    // print(takeInput());
    node *head = takeInput();
    print(head);
    int i, data;
    cin >> i >> data;
    head = insertNode(head, i, data);
    print(head);
    */

   node *head = takeInputBetter();
   head = reverseLL_3(head);
   print(head);

}