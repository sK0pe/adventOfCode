#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool hasSSL(string& check, unordered_set<string>& possibleSSL){
    for(int i = 0; i < (int)check.length() - 2; ++i){
        if(check[i] == check[i+2] && check[i] != check[i+1]){
            string temp;
            temp.push_back(check[i+1]);
            temp.push_back(check[i]);
            temp.push_back(check[i+1]);
            if(possibleSSL.count(temp)){
                return true;
            }
        }
    }
    return false;
}

void getABA(string& input, unordered_set<string>& possibleABA){
    for(int i = 0; i < (int)input.length() - 2; ++i){
        if(input[i] == input[i+2] && input[i] != input[i+1]){
            possibleABA.insert(input.substr(i, 3));
        }
    }
}

int main(){
    string inputLine;
    int count = 0;
    string prefix, bracketed;
    while(getline(cin, inputLine)){
        stringstream ss(inputLine);
        vector<string> superNet;
        vector<string> hyperNet;
        unordered_set<string> possibleSSL;
        while(getline(ss, prefix, '[')){
            getline(ss, bracketed, ']');
            superNet.push_back(prefix);
            hyperNet.push_back(bracketed);
        }

        for(auto &i : hyperNet){
            getABA(i, possibleSSL);
        }

        for(auto &s : superNet){
            if(hasSSL(s, possibleSSL)){
                ++count;
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}
