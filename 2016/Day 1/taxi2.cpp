#include <iostream>
#include<set>
using namespace std;

int main(){
	set<pair<int,int>> visited;
	visited.insert({0,0});

	int x = 0, y = 0;
	int direction = 0;

	char turn;
	int distance;

	while (cin >> turn >> distance){
		switch(turn){
			case 'L':
    			direction = (direction + 3) % 4;
    			break;
			case 'R':
    			direction = (direction + 1) % 4;
    			break;
		}

		for (int d=0; d < distance; ++d){
			switch(direction){
				case 0:
    				y += 1;
    				break;
				case 1:
    				x += 1;
    				break;
				case 2:
    				y -= 1;
    				break;
				case 3:
    				x -= 1;
    				break;
			}

			if (visited.find({x,y}) != visited.end()){
				cout << x << "," << y << " - " << abs(x) + abs(y) << endl;
				return 0;
			}
			else{
				visited.insert({x,y});
			}
		}

		cin.ignore(1,',');
	}

	//cout << "end: " << x << "," << y << " - " << abs(x) + abs(y) << endl;

	return 0;
}
