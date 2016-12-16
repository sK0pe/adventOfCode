#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <set>
using namespace std;

void tokeniser(string& str, string delimiter, vector<string> &tokens){
    auto start = str.find_first_not_of(delimiter, 0);
    auto end = start;
    while(end != string::npos){
        end = str.find(delimiter, start);
        tokens.push_back(str.substr(start, end - start));
        start = str.find_first_not_of(delimiter, end);
    }
}

int main(){
    string directionList;
    // readin entire line
    getline(cin, directionList);
    vector<string> directions;
    tokeniser(directionList, ", ", directions);

    int x = 0;
    int y = 0;
    char previousDirection = 'L';
    char currDir = 'L';
    int magnitude;
    int moveX = 1, moveY =1;
    set<pair<int, int>> history;
    history.insert({0, 0});

    for(int i = 0; i < (int)directions.size(); ++i){
        sscanf(directions[i].c_str(), "%c%d", &currDir, &magnitude);
        if(i % 2== 0){
            // affect x
            if(previousDirection == currDir){
                moveX *= -1;
            }
        }
        else{
            // affect y
            if(previousDirection == currDir){
                moveY *= -1;
            }
        }

        for(int m = 0; m < magnitude; ++m){
            if(i%2 == 0){
                x += moveX;
            }
            else{
                y+= moveY;
            }

            if(history.count({x, y}) > 0){
                cout << abs(x) + abs(y) << endl;
                return 0;
            }
            else{
                history.insert({x, y});
            }
        }
        previousDirection = currDir;
    }
    return 0;
}
