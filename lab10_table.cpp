#include<vector>
using std::vector;
#include<iostream>
using std::cout; using std::endl;using std::ostream;
#include<iomanip>
using std::setw;
#include<string>
using std::string; using std::to_string;
#include<iterator>
using std::ostream_iterator;
#include<algorithm>
using std::transform;
#include<sstream>
using std::ostringstream;
#include<random>
using std::mt19937_64; using std::uniform_int_distribution;
#include<stdexcept>
using std::out_of_range;
#include "lab10_table.h"

Table::Table(long w, long h, long f, long d){

	vector<long> temp;
	width_ = w;
	height_ = h;
	field_width_ = f;
  
	for(int i=0; i<h; i++){
  
		temp.clear();
    
		for(int j=0; j<w; j++){
    
			temp.push_back(d);
      
		} //of for
    
		table_.push_back(temp);
    
	} //of for
} //of constructor

void Table::fill_random(long l, long h, unsigned int s){

	mt19937_64 reng(s);
	uniform_int_distribution<long> dist(l,h);
  
	for(int i=0; i<height_; i++){
  
		for(int j=0; j<width_; j++){
    
		table_[i][j] = dist(reng);
      
		} //of for
	} //of for
} //of fill_random

bool Table::set_value(unsigned int i, unsigned int j, long val){

	if ((i >= 0 && i < width_) && (j >= 0 && j < height_)){
  
		table_[i][j] = val;
		return true;
    
	} //of if
  
	else{
  
		return false;
    
	} //of else
} //of set_value

long Table::get_value(unsigned int i, unsigned int j) const {

	if ((i >= 0 && i < width_) && (j >= 0 && j < height_)){
  
		return table_[i][j];
    
	} //of if
  
	else{
  
		throw out_of_range("illegal table bounds:" + to_string(i) + " " + to_string(j));
    
	} //of else
} //of get_value


ostream& operator<<(ostream& out, Table t){

	transform(t.table_.begin(), t.table_.end(),
		ostream_iterator<string>(out, "\n"), [&t](const vector<long>& tr) {
		
			ostringstream oss;
		
			for (auto e : tr){
	      
				oss << setw(t.field_width_) << e << ", ";
				
			} //of for
			
			string s = oss.str();
	      
			return s.substr(0, s.size()-2);
		} //of iterator
	    );
	    
	return out;
  
} //of operator
