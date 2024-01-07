#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;
    // koi guarantee nahi kis order mei aayenge
    // unordered map hai

     unordered_map<string, int>::iterator it = ourmap.begin();
     while(it != ourmap.end()) {
        cout << "key : " << it -> first << " value : " << it -> second << endl;
        it++;
     }
     // agar normal map/ordered map use kiya hota toh sorted order mei aata
     // inorder k sorted order 
     
     // find function 
     // map mei and vector mei bhi kaafi functions hai jo
     // iterators use krke hi kaam krte hai
     unordered_map<string, int>::iterator it2 = ourmap.find("abc"); // - will give us an iterator
     // passed key to function
     // will give us the address of that element
     // uske baad wale access kr skte h and usko bhi


     // erase function key leke delete kr rha tha
     // ourmap.erase(it2);
     // can pass iterator to erase function
     // iterator jahan point kr rha hai use delete kr dega

     // similarly, erase and find vectors mei bhi hota hai
     // woh bhi vectors k saath kaam krta hai

     // ourmap.erase(it2, (it2 + 4));
     // erase k andr hum starting and ending iterator de skte hai
     // this wil, delete it2, it2 + 1, it2 + 2, it2 + 3. will not involve the last one

     ourmap.erase(ourmap.begin(), ourmap.end());
     // this will empty the map 
     // end means last wale k baad

     // unordered map mei this next wala del krne ki cheez doesn't make any sense
     // because hume pta hi nahi h next wala kya h
     // vector mei it does. - del 3, 4, 5 - give iterator from 3 to 6

     
     
     
     // iterator over vector
     vector<int> v;
     v.push_back(1);
     v.push_back(2);
     v.push_back(3);
     v.push_back(4);
     v.push_back(5);
     v.push_back(6);
     // vector has an ordering.

     vector<int>:: iterator it1 = v.begin();
     while(it1 != v.end()) {
        // it is poiting towards tumhare vector ka ek element
        cout << *it1 << endl;
        it1++;
     }
}