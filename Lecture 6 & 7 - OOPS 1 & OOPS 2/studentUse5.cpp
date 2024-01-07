#include <iostream>
using namespace std;
#include "student3.cpp"

int main() {
    student s1(101, 20); // error yahi aa jayega
    s1.age = 20;
    // s1.rollNumber = 101; - not possible pehle hi garbage jaa chuka h
}
