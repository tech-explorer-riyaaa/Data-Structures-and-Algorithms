#include <iostream>
using namespace std;

int main(){

    string* sp = new string; // created a string dynamically
    // ab iss string ka humare pass pointer aa chuka h
    *sp = "def";
    cout << sp << endl; // string ka address
    cout << *sp << endl;

    string s = "abc"; // static allocation
    cout << s << endl;

    string s1;
    s1 = "def";
    cout << s1 << endl;
    // string k andr character array hi hai and other functions hai
    // kr ye bhi same kaam rha h jo hum character array se krte the

    // earlier 2D array for multiple strings
    // now arrays of strings - 1D

    string s2 = "abc";
    // cin >> s2; // breaks at space
    // to avoid breaking at tab
    getline(cin, s2);
    cout << s2 << endl;

    s2 = "defdef";
    // can change content with = operator

    // can treat it like array
    cout << s2[0] << endl;
    s2[0] = 'z';
    cout << s2 << endl;

    string s3 = s1 + s2;
    cout << s3 << endl;

    s += s2;
    cout << s << endl;

    cout << s.size() << endl; // can't do this with array - but built-in strlen func exists
    cout << s.length() << endl;

    cout << s.substr(3) << endl; // sub-string function
    cout << s.substr(3, 3) << endl;

    cout << s.find("def") <<endl; // index of def
}