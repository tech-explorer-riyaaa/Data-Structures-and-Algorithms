#include <iostream>
using namespace std;
#include <vector>


int main() {
    // vector<int> * vp = new vector<int>(); // dynamically allocation
    vector<int> v; // static allocation

    for(int i = 0; i < 100; i++) {
        cout << "capacity : " << v.capacity() << endl;
        cout << "size : " << v.size()  << endl; // size went from 1 to 100
        v.push_back(i + 1);
    }

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1] = 100;

    // don't use this for inserting element
    // v[3] = 1002; // - size inc nahi hoga, if needed - but agr space hai toh daal dega
    // v[4] = 1234; // - size inc nahi hoga, wese agr possible h toh daal dega
    // ye dono naye array mei nahi aayenge
    // terminal inka error nahi dikhayega pr error dega

    v.push_back(23);
    v.push_back(234);

    /*
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;
    cout << v[6] << endl;

    cout << "size : " << v.size() << endl;

    cout << v.at(2) << endl;
    cout << v.at(6) << endl;
    */

   // to delete last element
   v.pop_back();

//    for(int i = 0; i < v.size(); i++) {
//     cout << v[i] << endl;
//    }

}