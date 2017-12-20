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
using std::transform; using std::replace;
#include<sstream>
using std::ostringstream;
#include<random>
using std::mt19937_64; using std::uniform_int_distribution;
#include<stdexcept>
using std::out_of_range; using std::runtime_error;
#include "lab11_circbuf.h"

CircBuf::CircBuf(size_t x){

sz_=x;
cnt_=0;
front_=0;
back_=0;
buf_=vector<long>(x);

}

long CircBuf::front() const{
	
	string err = "Runtime Error";
	cout<<front_<<endl;
	if (!empty()){

		return buf_[front_];
	}
	
	else{
	cout<<"in front"<<endl;
		throw runtime_error(err);
	}
} //of front

long CircBuf::back() const{

	string err = "Runtime Error";
	
	if (!empty()){

		return buf_[back_-1];
	}
	
	else{
		throw runtime_error(err);
	}
} //of back

void CircBuf::remove(){

	string err = "Runtime Error";
	
	if (!empty()){

		front_++;
		front_=front_%sz_;
		cnt_--;
	}
	
	else{
		throw runtime_error(err);
	}
} //of remove

bool CircBuf::empty() const{

	if (cnt_ == 0){
		return true;
	}
	
	else{
		return false;
	}
} //of empty

bool CircBuf::full() const{

	if (cnt_ == sz_){
		return true;
	}
	
	else{
		return false;
	}
} //of full

void CircBuf::add(long x){
 
	string err = "Runtime Error"; 
	
	if (!full()){

		buf_[back_]=x;
		back_=(back_+1)%sz_;
		cnt_++;
	}
	
	else{
		throw runtime_error(err);
	}
} //of add

ostream& operator<< (ostream &out, const CircBuf &cb){

	string str;
	
	out << "Front Index: " << cb.front_ << endl;
	out << "Back Index: " << cb.back_ << endl;
	out << "Count: " << cb.cnt_ << endl;
	
	for (auto s : cb.buf_){
		str += to_string(s) + " ";
	}
	
	out << str << endl;
	
	return out;
	
} //of overloaded <<
