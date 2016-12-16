#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <cstdio>
#include <unordered_map>
using namespace std;

int main(){
    string encrypted;
    int code;
    string name, bracketed;

    regex rgx("^([a-z-]*)([0-9]*)\\[([a-z]*)\\]$", regex_constants::extended);
    //regex rgx("^([a-z-]*)", regex_constants::basic);
    smatch components;

    while(getline(cin, encrypted)){
        //stringstream ss(encrypted);
        //regex rgx("^([a-z]|-)+(\d)+[(\[a-z\]+)]$")
        if(regex_match(encrypted, components, rgx)){
            name = components[1];
            code = stoi(components[2]);
            bracketed = components[3];
        }
        else{
            cout << "didn't match " << encrypted << endl;
        }
        cout << name << '\n' << code << '\n' << bracketed << endl;
    }
    return 0;
}
