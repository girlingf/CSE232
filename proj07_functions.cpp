#include <iostream>
#include <vector>
using std::cout;using std::cin;using std::endl;
using std::vector; using std::stoi;
#include<string>
using std::string; using std::to_string;
#include<algorithm>
using std::remove; using std::set_intersection; using std::sort;
using std::transform; using std::count;
#include<sstream>
using std::stringstream;
#include<map>
using std::map;
#include<utility>
using std::pair; using std::make_pair;
#include<iterator>
using std::ostream_iterator;
#include<locale>
using std::locale; using std::tolower;
#include "proj07_functions.h"

/*
CSE232 Section 001
3/18/17
Project 07
*/

/*
The purpose of this function is to display all the key, value pairs within a
given map. This is done by going through each element of the map and appending
its key:value to a string. The completed string is returned.
*/
string map_to_string(map<string,long>  &m){

	string str;
	string temp;
	
	for (auto s : m){
		str.append(s.first);
		str.append(":");
		temp = to_string(s.second);
		str.append(temp);
		str.append(", ");
	} //of for
	
	str = str.substr(0, str.length()-2);
	
	return str;
	
} //of map_to_string

/*
The purpose of this function is to display all the key, value pairs within a
given vector. This is done by going through each element of the vector and
appending its key:value to a string. The completed string is returned.
*/
string vector_to_string(vector<pair<string,long>> &v){

	string str;
	string temp;
	
	for (auto j : v){
	
		str.append(j.first);
		str.append(":");
		temp = to_string(j.second);
		str.append(temp);
		str.append(", ");
	} //of for
	
	str = str.substr(0, str.length()-2);
	
	return str;
	
} //of vector_to_string

/*
The purpose of this function is to make all of the input string's letters
lowercase, and remove any non-alpha characters, as well as spaces. It returns
the modified string.
*/
string clean_string(string w){
	
	string str;
	str = w;
	locale loc;
	
	str.erase(remove_if(str.begin(), str.end(), [](char c)
		{return !isalpha(c);}), str.end());
	
	for (size_t i = 0; i<str.length(); ++i){
	
		str[i] = tolower(str[i], loc);
		
	} //of for

	return str;

} //of clean_string

/*
The purpose of this function is to create a vector of ngrams based on an input
string and ngram length. The function iterates through the string, creating
all the possible ngrams of the input length and stores them as a vector. The
function returns that vector.
*/
vector<string> generate_ngrams(string w, size_t n){
	
	vector<string> vect;
	string temp;
	
	for (unsigned int i = 0; w[i]; ++i){
		temp = w.substr(i,n);
		
		if (temp.length() == n){
			vect.push_back(temp);
		} //of if
	} //of for
	
	return vect;
	
} //of generate_ngrams

/*
The purpose of this function is to fill up a map of all ngrams and their
frequency given a string of text. The string is cleaned using the clean_string
function. A vector of ngrams is then created using the generate_ngrams function.
The vector is iterated through and adds pairs of ngrams and frequency to the
map. The functions returns nothing, but fills up the map due to referencing.
*/
void process_line(map<string, long> &m, string line, size_t n){

	string str;
	pair<string, long> p;
	vector<string> vect;
	
	str = clean_string(line);
	vect = generate_ngrams(str, n);
	
	for (auto j : vect){
	
		long mycount = count(vect.begin(), vect.end(), j);
		p = make_pair(j, mycount);
		m.insert(p);
		
	} //of for
	
} //of process_line

/*
The purpose of this function is to determine if the string in 1 pair is less
than the string in a 2nd pair. If string1 < string2, the function returns true.
Otherwise, the function returns false.
*/
bool pair_string_lessthan(const pair<string, long> &p1, const pair<string, 
	long> &p2){

	if (p1.first < p2.first){
		return true;
	} //of if
	
	else{
		return false;
	} //of it
	
} //of pair_string_lessthan

/*
The purpose of this function is to determine if the frequency of an ngram is 
greater than the frequency of another ngram. If the frequency of the 1st ngram 
is greater than the frequency of the 2nd ngram, the function returns true.
Otherwise, the function returns false.
*/
bool pair_frequency_greaterthan(const pair<string, long> &p1, const pair<string, 
	long> &p2){

	if (p1.second > p2.second){
		return true;
	} //of if
	
	else{
		return false;
	} //of if
	
} //of pair_frequency_greaterthan

/*
The purpose of this function is to determine the num most frequent ngrams in an
input map. All of the pairs from the map are placed into a vector that is sorted
in descending order of frequencies. If the frequency of multiple ngrams is the 
same, they are sorted alphabetically. The top num ngrams in terms of frequency
are returned in a separate vector.
*/
vector<pair<string, long>> top_n(map<string, long> &m, int num){
	
	vector<pair<string, long>> vect1;
	
	for (auto j : m){
		vect1.push_back(j);
	} //of for

	stable_sort(vect1.begin(), vect1.end(), pair_frequency_greaterthan);

	vector<pair<string, long>> vect2(vect1.begin(), vect1.begin()+num);
	
	return vect2;
	
} //of top_n

/*
The purpose of this function is to calculate the ochiai value of 2 input maps.
This is done by determining the number of elements in a set intersection of the
2 maps, and dividing it by the square root of the number of elements in each 
separate map multipled together. The function returns the ochiai value, K.
*/
double ochiai(map<string, long> &m1, map<string, long> &m2){

	double k;
	double numerator = 0;
	double denominator;
	
	for (auto j : m1){
	
		if (m2.count(j.first) > 0){
		
			numerator += 1;
		
		} //of if
	} //of for
	
	denominator = pow(m1.size() * m2.size(), 0.5);
	
	k = numerator / denominator;
	
	return k;
	
} //of ochiai
