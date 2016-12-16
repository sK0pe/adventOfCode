#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
using namespace std;


void printKeypad(vector<vector<char>>& keyPad){
    for(auto &i : keyPad){
        for(auto &j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
}

void loadKeypad(vector<vector<char>>& keyPad){
    int num = '1';
    char alpha = 'A';
    int row = 1;
    keyPad[row++][3] = num++;
    int i;
    for(i = 2; i < 5; ++i){
        keyPad[row][i] = num++;
    }
    ++row;
    for(i = 1; i < 6; ++i){
        keyPad[row][i] = num++;
    }
    ++row;
    for(i = 2; i < 5; ++i){
        keyPad[row][i] = alpha++;
    }
    ++row;
    keyPad[row][3] = alpha;
}


int main(){
    vector<vector<char>> keyPad(7, vector<char>(7, '0'));
    loadKeypad(keyPad);
    //printKeypad(keyPad);

    pair<int, int> curr = make_pair(3,1);
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

            if(keyPad[temp.first][temp.second] != '0'){
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
