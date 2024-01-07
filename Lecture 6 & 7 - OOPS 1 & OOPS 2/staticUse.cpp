#include <iostream>
using namespace std;
#include "static.cpp"

int main() {

    /*
    student s1; // def const data members m garbage value daal deta h

    cout << s1.rollNumber << " " << s1.age << endl;
    cout << s1.totalStudents << endl; // logically incorrect but works 
    cout << student :: totalStudents << endl;

    s1.totalStudents = 20;
    student s2;
    cout << s2.totalStudents << endl;
    cout << student :: totalStudents << endl;
    */

   student s1;
   student s2;
   student s3, s4, s5;
   cout << student :: getTotalStudents() << endl;

}