#include <iostream>
#include <sstream>
#include <string>
#include <regex>
using namespace std;
// regex parse{R"(^([a-z]+)\[([a-z]+)\][a-z]*$)"};

bool hasABBA(string& input){
    for(int i = 0; i < (int)input.length() - 3; ++i){
        if(input[i] == input[i+3] && input[i] != input[i+1] && input[i+1] == input[i+2]){
            return true;
        }
    }
    return false;
}

int main(){
    string inputLine;
    int count = 0;
    string prefix, suffix, bracketed;
    bool innerFlag;
    while(getline(cin, inputLine)){
        innerFlag = false;
        stringstream ss(inputLine);
        vector<string> superSet;
        vector<string> innerSet;
        while(getline(ss, prefix, '[')){
            getline(ss, bracketed, ']');
            superSet.push_back(prefix);
            innerSet.push_back(bracketed);
        }

        for(auto &i : innerSet){
            if(hasABBA(i)){
                innerFlag = true;
                break;
            }
        }

        if(innerFlag){
            continue;
        }

        for(auto &s : superSet){
            if(hasABBA(s)){
                ++count;
                break;
            }
        }
    }
    cout << count << endl;
}
