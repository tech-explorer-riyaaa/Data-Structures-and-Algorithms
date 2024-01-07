#include <iostream>
using namespace std;

#include "student.cpp"

int main(){

    student s1(10, 1001);
    cout << "s1 : ";
    s1.display();

    student s2(s1);
    cout << "s2 : ";
    s2.display();

    student *s3 = new student(20, 2001);
    cout << "s3 : ";
    s3 -> display();

    student s4(*s3);

    student *s5 = new student(*s3);
    student *s6 = new student(s1);

    // correct way of dynamic creation - student *s3 - * and variable name together.

    student s7(10, 1001);
    student s8(20, 2001);
    student *s9 = new student(30, 3001);

    // copy assignment operator
    s8 = s7;
    *s9 = s7; // defer before using dynamically created object

    // main se bahar aane se just pehle humare objects k liye destructor call ho jayega
    // jaise constructor automatically call ho jaata hai, hume explicitly call krne ki zaruart nahi padti
    // wese hi destructor bhi apne aap call ho jayega

    delete s3;
    delete s5;
    delete s6;
    delete s9;
     
}