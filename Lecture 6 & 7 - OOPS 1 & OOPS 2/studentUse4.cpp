#include <iostream>
using namespace std;
#include "student.cpp"

int main(){
    student s1; // constructor 1 called
    student s2(101); // constructor 2 called
    student s3(20, 102); // constructor 3 called

    student s4(s3); // copy constructor is called
    s1 = s2; // copy assignment operator is called; no constructor is called - they are already created in memory

    student s5 = s4; // copy constructor called
}