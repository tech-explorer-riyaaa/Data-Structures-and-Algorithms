#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> ourmap;
    // insert
    pair<string, int> p("abc", 1); 
    ourmap.insert(p);

    // other way in C++
    ourmap["def"] = 2;

    // find or access
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;
    // cout << ourmap.at("ghi") << endl; // got exception, key not found. program crashed.
    cout << "size :" << ourmap.size() << endl;
    cout << ourmap["ghi"] << endl; // - weird - doesn't give error || insert kr dega default value which is 0. and returns 0
    cout << "size :" << ourmap.size() << endl;


    // check presence
    if (ourmap.count("ghi") > 0) {
        // can use either [] or at
        cout << "ghi is present" << endl;
    }
    // will print as [] inserted it above

    // can update via insert as well - naya nahi banayega woh

    // erase
    ourmap.erase("ghi");
    cout << "size :" << ourmap.size() << endl;

    if (ourmap.count("ghi") > 0) {
        // can use either [] or at
        cout << "ghi is present" << endl;
    } else {
        cout << "ghi is not present" << endl;
    }

}