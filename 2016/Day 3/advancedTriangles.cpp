#include <iostream>
#include <vector>
using namespace std;

int countTriangles(vector<int>& arr){
    int count = 0;
    for(int i = 0; i < (int)arr.size() - 2; i += 3){
        if(arr[i] + arr[i+1] > arr[i+2]
            && arr[i+1] + arr[i+2] > arr[i]
                && arr[i] + arr[i+2] > arr[i+1]){
                    ++count;
        }
    }
    return count;
}


int main(){
    vector<vector<int>> arr(3, vector<int>());
    int a, b, c, count = 0;

    while(cin >> a >> b >> c){
        arr[0].push_back(a);
        arr[1].push_back(b);
        arr[2].push_back(c);
    }

    for(auto &row : arr){
        count += countTriangles(row);
    }

    cout << count << endl;

    return 0;
}
