#include <iostream>
using namespace std;
// #include vehicle.cpp
#include "HondaCity.cpp"

int main() {
    /*
    vehicle v;

    // with access modifier of car class - public

    v.color = "blue";
    // v.maxSpeed = 100;  - private member
    // v.numTyres = 4; - protected member
     
    // car c; - can't call default now
    car c(50);
    c.color = "black";
    // c.numTyres = 4; - not accessible - protected hai - can be used only in derived classes
    c.numGears = 5;

    */

   HondaCity h(4, 5);

}

// run this file to know the order of constructors & destructors in inheritance