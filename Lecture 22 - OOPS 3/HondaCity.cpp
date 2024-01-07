#include "car.cpp"
#include <iostream>

class HondaCity : public car {
    public :
    HondaCity(int x, int y) : car(x, y) {
        cout << "Honda city constructor " << endl;
    }

    ~HondaCity() {
        cout << "Honda City destructor" << endl;
    }
};