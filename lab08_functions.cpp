#include<iostream>
using std::cout; using std::endl;
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
#include"lab08_functions.h"

long collatz (long n){
	
	long x;
	
	if (n%2 == 0){
		x = n/2;
	}

	else{
		x = 3 * n + 1;
	}
	
	return x;

} //of collatz

string pair_to_string (const pair<long, vector<long>> &p){

	ostringstream oss;
	oss << p.first <<":";
	for (auto s : p.second){
			oss << s << ",";
	}
	oss << endl;
	return oss.str();


} //of pair_to_string

void fill_vector (map<long, vector<long>> &m, vector<long> &v, long start){
	
	vector<long> v2;
	
	if(start == 1)
	{
		v.push_back(start);
	}
	for (long i = start; i != 1;){
		v2.clear();
		v.push_back(i);
		if (m.count(i) == 1){
			cout << "For " << start << " program copies the rest from " << i << endl;
			v2 = m.find(i)->second;
			v.insert(v.end(), v2.begin()+1, v2.end());
			i = 1;
			
		} //of if 
		else{
			i = collatz(i);
			if(i == 1){
				v.push_back(i);
			}	
		} //of else
		
	} //of for

} //of fill_vector
