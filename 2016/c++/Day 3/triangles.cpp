#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a, b, c, count = 0;

    while(cin >> a >> b >> c){
        //cout << a << ' ' << b << ' ' << c << endl;
        if(a + b > c && a + c > b && b + c > a){
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
