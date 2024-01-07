#include <iostream>
using namespace std;

int subs(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    } // base case

    string smallString = input.substr(1);
    int smallOutputSize = subs(smallString, output);

    for (int i = 0; i < smallOutputSize; i++){
        output[i + smallOutputSize] = input[0] + output[i]; // can concatenate character into a string as well
    }
    return 2 * smallOutputSize;
}

int main(){
    string input;
    cin >> input;
    string* output = new string[1000];
    // abhi size 1000 krre h tum 2 ki power n k hisab se krna
    // dynamic allocation
    int count = subs(input, output);
    for(int i = 0; i < count; i++){
        cout << output[i] << endl;
    }
}