#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <unordered_map>
using namespace std;

char maxCharacter(unordered_map<char, int>& count, bool max){
    char maxChar = 'a';
    int maxCount = count['a'];
    for(char c = 'a'; c <= 'z'; ++c){
        if(count[c] > maxCount && max){
            maxChar = c;
            maxCount = count[c];
        }
        if(!max && count[c] < maxCount && count[c] > 0){
            maxChar = c;
            maxCount = count[c];
        }
    }
    return maxChar;
}


int main(){
    string code;
    cin >> code;
    vector<unordered_map<char, int>> count(code.length(), unordered_map<char, int>());
    string signal;

    for(int i = 0; i < (int)code.length(); ++i){
        count[i].insert(make_pair(code[i], 1));
    }

    while(cin >> code){
        for(int i = 0; i < (int)code.length(); ++i){
            if(count[i].count(code[i]) == 0){
                count[i].insert(make_pair(code[i], 1));
            }
            else{
                count[i][code[i]]++;
            }
        }
    }

    for(auto& s : count){
        signal += maxCharacter(s, false);
    }


    cout << signal << endl;
    return 0;
}
