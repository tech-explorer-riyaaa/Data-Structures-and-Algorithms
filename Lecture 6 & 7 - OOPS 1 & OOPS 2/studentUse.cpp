#include <iostream>
using namespace std;
#include "student.cpp" // included that file here - that whole code is placed / copied here

int main(){
    // create objects statically
    student s1;
    student s2;
    student s3, s4, s5;

    // create objects dynamically
    student * s6 = new student;

    // setting and accessing properties
    // s1.age = 24;
    s1.rollNumber = 101;

    cout << "s1 age : " << s1.getAge() << endl;
    cout << "s1 roll number : " << s1.rollNumber << endl;

    // s2.age = 30;

    // (*s6).age = 24;
    ( *s6).rollNumber = 104;
    // shortcut to write above two lines
    // s6 -> age = 23;
    s6 -> rollNumber = 105;

    // getters and setters

    cout << "s1 : ";
    s1.display();
    cout << "s2 : ";
    s2.display();
    cout << "s6 : ";
    (*s6).display();
    cout << "s6 : ";
    s6 -> display(); // no arguments required in this function

    cout << "s6 age : " << s6 -> getAge() << endl;

}