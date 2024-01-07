#include "vehicle.cpp"
#include <iostream>

class car : public vehicle { // access modifier - public
     public:
     int numGears;

     // car() : vehicle() { // represent aise krte hai - initialization list - likhne ki zarurat nahi h - ye implicitly ho rha h

     // car() : vehicle(5) {} - need
    //  car() {
    //     // ye pehle vehicle ka constr call kr dega implicitly
    //     cout << "car's default constructor " << endl;
    //  }

    // car() : vehicle(5) {
    //     // ye pehle vehicle ka constr call kr dega implicitly
    //     cout << "car's default constructor " << endl;
    //  }

    car(int x, int y) : vehicle(x) {
        // ye pehle vehicle ka constr call kr dega implicitly
        cout << "car's parametrized constructor " << endl;
        numGears = y;
     }

     ~car() {
        cout << "car's default destructor " << endl;
     }

     void print() {
        cout << "NumTyres : " << numTyres << endl;
        cout << "color : " << color << endl;
        cout << "NumGears : " << numGears << endl;
        // cout << "MaxSpeed : " << maxSpeed << endl; - can't access max speed
     }
};