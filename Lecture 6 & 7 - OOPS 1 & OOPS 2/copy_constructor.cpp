#include <iostream>
#include <cstring>
using namespace std;
#include "student2.cpp"

int main() {
    char name[] = "abcd";
    student s1(20, name);
    s1.display();

    student s2(s1); // in-built copy constructor
    s2.name[0] = 'x'; 
    s1.display();
    s2.display();
}