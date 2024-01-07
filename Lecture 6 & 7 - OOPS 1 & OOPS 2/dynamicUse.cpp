#include <iostream>
using namespace std;
#include "dynamicArray.cpp"

int main(){
    dynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.print();

    dynamicArray d2(d1); // called our designed copy constructor 
    // calling copy constructor - shallow copy
    // naya array nahi banaya
    // iske array k address yani data mei d1 k array ka address gaya h, nextIndex mei bhi wohi same value... all values same
    d1.add(0, 100);
    d2.print();

    dynamicArray d3;
    d3 = d1; // our designed copy instructor do deep copy instaed of shallow copy as in in-built copy assignment operator
    d1.add(0, 200);
    
    d3.print();
}