#include <iostream>
#include <fstream>
using namespace std;

int main(){
	
	ifstream elevator_info("elevator.txt");
	if(elevator_info.fail()){
		cerr << "File does not exist!" << endl;
	}
	bool first = true;

	char check;
	int floor = 0;
	int position = 1;
	while(!elevator_info.eof()){
		elevator_info.get(check);
		if(check == '(') ++floor;
		if(check == ')') --floor;
		if(first && floor == -1){
			first = false;
			cout << "Santa goes to the basement for the first time at position " << position << endl;
		}
		++position;
	}

	cout << "Santa is on level " << floor << " of the building." << endl;
	return 0;
}
