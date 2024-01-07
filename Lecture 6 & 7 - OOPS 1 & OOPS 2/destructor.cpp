#include <iostream>
using namespace std;

#include "student.cpp"

int main(){
    student s1(10, 1001);
    student s2(20, 2001);
    student *s3 = new student(30, 3001);

    // only two times destructor called!

    delete s3;
    // now three times destructor called:
}