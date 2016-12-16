#include <iostream>
#include <string>
#include <regex>
using namespace std;
// regex parse{R"(^([a-z]+)\[([a-z]+)\][a-z]*$)"};

bool hasABBA(string input){
    for(int i = 0; i < (int)input.length() - 3; ++i){
        if(input[i] == input[i+3] && input[i] != input[i+1] && input[i+1] == input[i+2]){
            return true;
        }
    }
    return false;
}

int main(){
    string inputLine;
    //regex parse{R"(^([a-z]+)\[([a-z]+)\]([a-z]+)$)"};
    smatch matches;
    int count = 0;
    while(getline(cin, inputLine)){
        if(regex_match(inputLine.cbegin(), inputLine.cend(), matches, regex(R"(^([a-z]*)\[([a-z]*)\]([a-z]*)$)"))){
            if(hasABBA(matches.str(1)) && (hasABBA(matches.str(1)) || hasABBA(matches.str(2)))){
                ++count;
            }
        }
    }
    cout << count << endl;
}
