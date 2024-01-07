#include <iostream>
// #include "student.cpp" - it gives COMPILATION ERROR here.
using namespace std;
#include "student.cpp"
int main(){
    student s1;
    student * s2 = new student;

    s1.setAge(20, 1234);
    s2 -> setAge(24, 1234);

    s1.rollNumber = 101;
    s2 -> rollNumber = 102;

    s1.display();
    s2 -> display();
}