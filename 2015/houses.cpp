#include <iostream>
#include <unordered_set>
#include <functional>
#include <fstream>
using namespace std;

struct hash_pair{
	size_t operator()(const pair<int, int> &coordinates)const{
		return hash<int>()(coordinates.first)^hash<int>()(coordinates.second);
	}
};

int main(int argc, char** argv){
	ifstream directions(argv[1]);
	if(directions.is_open()){
		char nextMove;
		int x, y = 0;
		unordered_set<pair<int, int>, hash_pair> visited;
		visited.insert({0,0});
		while(!directions.eof()){
			directions.get(nextMove);
			switch(nextMove){
				case '<':
					--x;
					break;
				case '>':
					++x;
					break;
				case '^':
					++y;
					break;
				case 'v':
					--y;
					break;
				case 'V':
					--y;
					break;
				default:
					break;	
			}					  
			visited.insert({x, y});
		}
		cout << "Number of unique houses visited = " << visited.size() << endl;
		directions.close();
		return 0;
	}
	else{
		cerr << "No such file exists!" << endl;
		return 1;
	}
}
