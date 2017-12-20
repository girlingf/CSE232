#include<iostream>
using std::cout; using std::endl; using std::cin;
#include<iomanip>
using std::setw;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;
#include<algorithm>
using std::transform;
#include<utility>
using std::pair; using std::make_pair;
#include<map>
using std::map;
#include<iterator>
using std::ostream_iterator;
#include"lab08_functions.h"

int main(){

	long low, high;
	map<long, vector<long>> collatz_map;
	vector<long> vect;
	vector<long> v2 = {0,0,0};

	cout << "Enter a low value:" << endl;
	cin >> low;
	cout << "Enter a high value:" << endl;
	cin >> high;
	
	for (long i = low; i <= high; ++i){
	
		vect.clear();
		fill_vector(collatz_map, vect, i);
		collatz_map[i] = vect;
		

			
	} //of for
	vector<std::size_t> v3 (3,0);
	
	for(auto s: collatz_map)
	{	
		string str = pair_to_string(s);
		cout << str.substr(0, str.size()-2) << endl;

	} //of for
	
	

} //of main
