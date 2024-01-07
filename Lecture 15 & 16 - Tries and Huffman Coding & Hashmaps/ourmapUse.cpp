#include <iostream>
#include "ourmap.h"
using namespace std;

int main() {
    ourmap<int> map;
    for(int i = 0; i < 10; i++) {
        char c = '0' + i; // i ki value 5 hai toh use '5' mei convert kr rhe h
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout << map.getLoadFactor() << endl;
    }

    cout << map.size() << endl;

    // do baar rehashing honi chaiye - at 4 and 8 - size 20 buckets
    map.remove("abc2");
    map.remove("abc7");

    for(int i = 0; i < 10; i++) {
        char c = '0' + i; // i ki value 5 hai toh use '5' mei convert kr rhe h
        string key = "abc";
        key = key + c;
        cout << key << " : " << map.getValue(key) << endl;
    }
    cout << map.size() << endl;
}