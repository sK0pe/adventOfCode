#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int ROWS = 6;
int COLS = 50;

void fillRectangle(vector<vector<bool>>& grid, int numCols, int numRows){
    //numCols = min(numCols, COLS);
    for(int r = 0; r < numRows; ++r){
        for(int c = 0; c < numCols; ++c){
            grid[r][c] = true;
        }
    }
}

void moveAlong(vector<vector<bool>>& grid, int row, int positions){
    vector<bool> temp(COLS);
    for(int c = 0; c < COLS; ++c){
        temp[c] = grid[row][c];
    }
    for(int c = 0; c < COLS; ++c){
        grid[row][(c + positions)%COLS] = temp[c];
    }
}

void moveDown(vector<vector<bool>>& grid, int column, int positions){
    vector<bool> tempCol(ROWS);
    for(int r = 0; r < ROWS; ++r){
        tempCol[r] = grid[r][column];
    }
    for(int r = 0; r < ROWS; ++r){
        grid[(r + positions)%ROWS][column] = tempCol[r];
    }
}

int countPixels(vector<vector<bool>>& grid){
    int count = 0;
    for(int r = 0; r < ROWS; ++r){
        for(int c = 0; c < COLS; ++c){
            if(grid[r][c]){
                ++count;
            }
        }
    }
    return count;
}

void printPixels(vector<vector<bool>>& grid){
    for(int r = 0; r < ROWS; ++r){
        for(int c = 0; c < COLS; ++c){
            if(grid[r][c]){
                cout << '#';
            }
            else{
                cout << '.';
            }
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    vector<vector<bool>> display(COLS, vector<bool>(ROWS, false));
    string instruction;
    while(getline(cin, instruction)){
        stringstream dirs(instruction);
        string prefix, middle;
        char midChar;
        int A = 0, B = 0;
        switch(instruction[7]){
            case 'r':{
                // Rotate row
                dirs.ignore(13);
                dirs >> A >> middle >> B;
                moveAlong(display, A, B);
                break;
            }
            case 'c':{
                // Rotate column
                dirs.ignore(16);
                dirs >>  A >> middle >> B;
                moveDown(display, A, B);
                break;
            }
            default:{
                // fill rectangle
                dirs.ignore(5);
                dirs >> A >> midChar >> B;
                fillRectangle(display, A, B);
                break;
            }
        }
    }
    printPixels(display);
    cout << countPixels(display) << endl;
    return 0;
}
