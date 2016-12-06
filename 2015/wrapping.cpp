#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
	int totalPaper = 0;
	int totalRibbon = 0;
	ifstream measurements(argv[1]);
	if(measurements.is_open()){
		string line;
		int dimensions[3];
		while(getline(measurements, line)){
			stringstream measurement(line);
			fill(dimensions,dimensions + 3, 0);
			measurement >> dimensions[0];
			measurement.ignore();
			measurement >> dimensions[1];
			measurement.ignore();
			measurement >> dimensions[2];
			sort(dimensions, dimensions+3);
			int lw = dimensions[0]*dimensions[1];
			int lh = dimensions[0]*dimensions[2];
			int wh = dimensions[1]*dimensions[2];
			totalPaper += 2*(lw + lh + wh) + lw;
			totalRibbon += dimensions[0]*dimensions[1]*dimensions[2] + 2*(dimensions[0] + dimensions[1]);
		}
		measurements.close();
		cout << "Total paper required by the elves is " << totalPaper << 
		"\nand the total ribbon required is " << totalRibbon << endl ;
		return 0;
	}
	else{
		cerr << "\nFile does not exist!\n" << endl;
		return 1;
	}
}
