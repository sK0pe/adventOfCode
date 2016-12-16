#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <set>
#include <map>
using namespace std;

struct customComparator{
    bool operator()(const pair<int, char> a, const pair<int, char> b)const{
        if(a.first == b.first){
            return a.second < b.second;
        }
        else{
            return a.first > b.first;
        }
    }
};


bool getValidSectors(string name, int sectorId, string& checksum){
    unordered_map<char, int> allChars;
    for(auto &c : name){
        if(allChars.count(c) == 0){
            allChars.insert(make_pair(c, 1));
        }
        else{
            allChars[c]++;
        }
    }

    multiset<pair<int, char>, customComparator> sortedChars;
    for(auto &c : allChars){
        sortedChars.insert(make_pair(c.second, c.first));
    }

    stringstream output;
    int n = 0;
    auto i = sortedChars.begin();
    while(i != sortedChars.end() && n < 5){
        output << (*i).second;
        ++i;
        ++n;
    }

    return output.str() == checksum;
}

void decryptName(string name, int code){
    for(auto& c : name){
        c = (c== '-') ? ' ': (c - 'a' + code)%26 + 'a';
    }
    if(name.find("north") != string::npos){
        cout << name << ' ' << code << endl;
    }
}

int main(){
    string encrypted;
    int code;
    string temp, checksum;
    // regex
    // regex parse{R"(^([a-z-]+)-(\d+)\[([a-z]*)\]$)"}; 
    int sumSectorIDs = 0;

    while(getline(cin, encrypted)){
        stringstream ss(encrypted);
        stringstream name;
        while(getline(ss, temp, '-')){
            name << temp;
            if(isdigit(ss.peek())){
                break;
            }
        }
        ss >> code;
        ss.ignore();
        getline(ss, checksum, ']');

        if(getValidSectors(name.str(), code, checksum)){
            sumSectorIDs += code;
            decryptName(name.str(), code);
        }
    }

    cout << sumSectorIDs << endl;

    return 0;
}
