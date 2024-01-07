#include <iostream>
using namespace std;

#include "student.cpp"
int main(){

    student s1;
    s1.display();

    student s2;

    student * s3 = new student;
    s3 -> display();

    cout << "Parameterized Constructor Demo" << endl;

    student s4(10);
    s4.display();

    // for one object, only one constructor will be called.
    // that too only once, at the time of its creation.

    student * s5 = new student(101);
    s5 -> display();

    student s6(20, 1002);
    // s6.student(20, 1002) - internally interpreted
    s6.display();

    // use of this keyword

    student s7(10, 1001);
    cout << "address of s7 : " << &s7 << endl;

    student s8(20);
    s8.display();
}