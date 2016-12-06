// start at x = 0, y = 0
// start +ve x plane, r = +ve
// even moves always affect x plane
// odd moves always affect y plane
//
//
// 0,0 x += 2 as direction = r, -1 modifier as r
// 2,0 switch to y as odd y +=
//
// contiguous similar directions give -ve number
//
// r2
// x+=2
// l2
// y+=2
//
// l2
// x-=2
// l2
// y-=2
//
// r2
// x+=2
// r2
// y-=2
// r2
// x -=2
//
// 0 , -2
//
// r5
// x+=5
// l5
// y+=5
// r5
// x+=5
// r3
// y-=3
//
// 10,2

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
    int modX = 1, modY =1;
    set<pair<int, int>> history;
    bool foundCrossOver = false;
    history.insert(make_pair(0,0));
    pair<int, int> crossOver;

    for(int i = 0; i < (int)directions.size(); ++i){
        cout << directions[i] << endl;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;

        sscanf(directions[i].c_str(), "%c%d", &currDir, &magnitude);

        if(i % 2== 0){
            // affect x
            if(previousDirection == currDir){
                modX *= -1;
            }
            x += modX * magnitude;
        }
        else{
            // affect y
            if(previousDirection == currDir){
                modY *= -1;
            }
            y += modY * magnitude;
        }
        previousDirection = currDir;

        auto newCoord = make_pair(x, y);
        if(!foundCrossOver && history.count(newCoord) > 0){
            crossOver = newCoord;
            foundCrossOver = true;
            cout << "found crossover" << endl;
        }
        else{
            history.insert(make_pair(x,y));
        }
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;        
    }
    cout << abs(x) + abs(y) << "from 0 to end point" << endl;
    cout << abs(crossOver.first) + abs(crossOver.second) << "from first cross over to end" << endl;
    return 0;
}
