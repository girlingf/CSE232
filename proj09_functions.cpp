#include <iostream>
#include <iomanip>
using std::setprecision;
#include <vector>
using std::cout;using std::cin;using std::endl;
using std::vector; using std::stoi;
#include<string>
using std::string; using std::to_string;
#include<algorithm>
using std::remove; using std::set_intersection; using std::sort;
using std::transform; using std::count;
#include<sstream>
using std::stringstream; using std::istringstream;
#include<map>
using std::map;
#include<utility>
using std::pair; using std::make_pair;
#include<iterator>
using std::ostream_iterator;
#include<locale>
using std::locale; using std::tolower;
#include<fstream>
using std::ifstream;
#include<stdexcept>
using std::domain_error;
#include<math.h> 
#include "proj09_functions.h"

/*
CSE232 Section 001
4/5/17
Project 09
*/

/*

*/
FSA::FSA(string strt, string stp){

	start_ = strt;
	finish_ = stp;
	state_ = strt;
	
} //of constructor

/*

*/
FSA::FSA(ifstream& in){

	string str, temp2, temp3;
	
	getline(in, str, '\n');
	istringstream sk(str);
	
	sk >> temp2 >> temp3;

	start_ = temp2;
	finish_ = temp3;
	state_ = temp2;

	while (!in.fail()){
	
		string str;
		string start, finish, input;
		
		getline(in, str, '\n');
		istringstream ss(str);
		ss >> start >> input >> finish;
		
		if (start != ""){
			table_[start][input] = finish;		
		} //of if
	} //of while
	
} //of constructor

/*

*/
bool FSA::exists_state(string s){

	if (table_.count(s) == 1){
		return true;
	} //of if
	
	else{
		return false;
	} //of else
	
} //of exists_state

/*

*/
void FSA::add_state(string s){

	string err = s + " already exists";

	if (!exists_state(s)){
	
		table_[s];
		
	} //of if 
	
	else{
		throw domain_error(err);
	} //of else
	
} //of add_state

/*

*/
void FSA::add_transition(string s1, string input, string s2){

	string err = s1 + " doesn't exist";

	if (exists_state(s1)){
	
		table_[s1][input] = s2;
	
	} //of if 
	
	else{
		throw domain_error(err);
	} //of else
	
} //of add_transition

/*

*/
string FSA::transitions_to_string(string s){
	
	string str;
	string err = s + " doesn't exist";
	
	if (exists_state(s)){
		for (auto v : table_){
		
			str += v.first + ": ";
		
			for (auto w : v.second){
			
				str += "on " + w.first + " -> " + w.second + ", ";

			} //of for
			str = str.substr(0, str.length()-2);
			str += '\n';
		} //of for
		
		str = str.substr(0, str.length()-1);
		return str;
		
	} //of if
	
	else{
		throw domain_error(err);
	} //of else
} //of transitions_to_string

/*

*/
string FSA::next(string s, string input){
	
	string err1 = s + " doesn't exist";
	string err2 = s + " has no transition on input " + input;
	string str;
	
	if (exists_state(s)){
	
		if (table_[s].count(input) > 0){
		
			str = table_[s][input];
			return str;
			
		} //of if

		else{
			throw domain_error(err2);
		} //of else
		
	} //of if 
	
	else{
		throw domain_error(err1);
	} //of else
	
} //of next
	
/*

*/
bool FSA::run(string input){
	
	for (unsigned int i = 0; i < input.length(); ++i){

		if (input[i]-48 == 1){
		
			state_ = start_;
			cout << "Got to:" << state_ << " on a " << input[i] << endl;
			
		} //of if
		
		else{
		
			state_ = next(state_, to_string(input[i]-48));
			cout << "Got to:" << state_ << " on a " << input[i] << endl;
			
		} //of else
	} //of for
	
	if (state_ == finish_){
		return true;
	} //of if
	
	else{
		return false;
	} //of else
} //of run

/*

*/
ostream& operator<<(ostream& o, FSA& f){

	string str;
	
	str = "Start:" + f.start_ + ", Finish:" + f.finish_
		+ ", Present:" + f.state_;
	
	o << str << endl;
	o << f.transitions_to_string(f.start_) << endl;
	
	return o;
	
} //of overloaded operator<<
