#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <string>
#include <thread>
#include <vector>
#include "cheat.h"
using namespace std;
string doorID = "abbhdwsy";

void read_nums(char* s, string& out){
    stringstream output;
    for(int j=0;j<(int)strlen(s);j++){
        output << s[j];
    }
}

int main(){
    string password = "~~~~~~~~";
    int index = 0, found = 0;
    string hash;
    int position;
    while(found < 8){
        string checkCombo = doorID + to_string(index);
        hash = MD5(checkCombo).hexdigest();


        if(hash.substr(0,5) == "00000" && (char)hash[5] >= '0' && (char)hash[5] <'8'){
            position = (char)hash[5] - '0';
            if(password[position] == '~'){
                password[position] = hash[6];
                ++found;
            }
        }
        index++;
    }
    cout << password << endl;
    return 0;
}
