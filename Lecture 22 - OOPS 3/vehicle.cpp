#include <string>
using namespace std;

class vehicle {
    private:
        int maxSpeed;

    protected:
        int numTyres;

    public:
        string color;

        vehicle() {
            cout << "vehicle's default constructor " << endl;
        }

        vehicle (int z) {
            cout << "vehicle's parametrized constructor " << endl;
            maxSpeed = z;
        }

        ~vehicle() {
            cout << "vehicle's default destructor " << endl;
        }
};