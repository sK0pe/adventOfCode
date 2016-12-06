#include <iostream>
#include <unordered_set>
#include <functional>
 
using namespace std;
 
//typedef pair<int,int> Name;
 
struct hash_name {
    size_t operator()(const pair<int,int> &name ) const
    {
        return hash<int>()(name.first) ^ hash<int>()(name.second);
    }
};
 
int main(int argc, char* argv[])
{
    unordered_set<pair<int,int>,hash_name> ids;
    //ids[pair<int,int>(0, 1)] = 40561;
    //ids[pair<int,int>(2,2)] = 40562;
    ids.insert({0,1});
	ids.insert({2,2});
	ids.insert({2,2});

	cout << "number of unique pairs = " << ids.size() << endl;

	/*for ( auto ii = ids.begin() ; ii != ids.end() ; ii++ )
        cout << ii->first.first 
             << " "
             << ii->first.second 
             << " : "
             << ii->second
             << endl;*/
    return 0;
}
