#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
using namespace std;


void printKeypad(vector<vector<int>>& keyPad){
    for(auto &i : keyPad){
        for(auto &j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
}

void loadKeypad(vector<vector<int>>& keyPad){
    int num = 1;
    for(int i = 0; i < (int)keyPad.size(); ++i){
        for(int j = 0; j < (int)keyPad.size(); ++j){
            keyPad[i][j] = num++;
        }
    }
}


int main(){
    vector<vector<int>> keyPad(3, vector<int>(3, 0));
    loadKeypad(keyPad);

    pair<int, int> curr = make_pair(1,1);
    pair<int, int> temp;

    string instructions;
    stringstream code;
    while(cin >> instructions){
        for(auto &move : instructions){
            //cout << curr.first << ", " << curr.second << " - " << keyPad[curr.first][curr.second] << endl;
            temp = curr;
            //cout << move << endl;
            switch(move){
                case 'L':
                    temp.second -= 1;
                    break;
                case 'R':
                    temp.second += 1;
                    break;
                case 'U':
                    temp.first -= 1;
                    break;
                case 'D':
                    temp.first += 1;
                    break;
            }

            if(temp.first > -1 && temp.second > -1 && temp.first < 3 && temp.second < 3){
                //cout << "out of keypad" << endl;
                curr = temp;
            }
            //cout << curr.first << ", " << curr.second << " - " << keyPad[curr.second][curr.first] << endl;
        }
        //cout << "\n" << keyPad[curr.second][curr.first] << endl;
        code << keyPad[curr.first][curr.second];
    }
    cout << code.str() << endl;

    return 0;
}
