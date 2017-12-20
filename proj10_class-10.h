#ifndef class10_h
#define class10_h

#include<iostream>
using std::cout; using std::cin; using std::endl;
using std::ostream; using std::boolalpha; using std::isalpha;
#include<iterator>
using std::ostream_iterator;
#include<map>
using std::map;
#include<string>
using std::string; using std::to_string;
#include<stdexcept>
using std::overflow_error; using std::underflow_error;
#include<algorithm>
using std::swap;
using std::copy;
#include<initializer_list>
using std::initializer_list;
#include<sstream>
using std::ostringstream;
#include<type_traits>

/*
CSE232 Section 001
4/15/17
Project 10
*/



template<typename T> //class is templated
	
class BiStack{ //Bistack class
	
private: //non-accessible to the user

	T *data_; //allocate memory
	size_t capacity_;
	size_t size_;
	size_t cap_;
	int top1_;
	int top2_;
	
	/*
	The purpose of this function is to increase the amount of memory allocated
	to the BiStack if it becomes larger than the amount originally allocated to
	it. There is no return.
	*/
	void grow_and_copy(){
	
		string err = "stack past max";
	
		if (2*capacity_ <= size_){
		
			T *new_data;
			T num = 0;
		
			if (cap_ == capacity_){
		
				new_data = new T[2*capacity_];
				
				for (unsigned int i = 0; i < cap_ + 1; ++i){
				
					swap(data_[i], new_data[i]);
					
				} //of for
				
				delete [] data_;
				data_ = new_data;
				capacity_ = 2*capacity_;
			
				for (unsigned int j = cap_; j == capacity_; ++j){

					data_[j] = num;
					
					/*if (std::is_same<T, string>::value == 1){
						T num = 0;
						data_[j] = num;
					} //of if 
					
					else{
						T num = 0;
						data_[j] = num;
					} //of else	*/
				} //of for
			} //of if
		} //of if
		
		else{
			throw overflow_error(err);
		} //of else
		
	} //of grow_and_copy
	
public: //accessible to the user

	/*
	The purpose of this constructor is to create a BiStack object. It
	initializes the object based on user input or default values.
	*/
	BiStack(size_t capacity = 4, size_t size = 16){
	
		capacity_ = capacity; //initial array size
		size_ = size; //max array size
		data_ = new T[capacity_];
		cap_ = 0; //number of elements in array
		top1_ = -1; //iterator for first stack
		top2_ = -1; //iterator for second stack
		
	
	}; //of constructor
	
	/*
	The purpose of this constructor is to create a BiStack object. It
	initializes the object based on user input or default values.	
	*/
	BiStack(initializer_list<T> init_l , size_t size = 16){
	
		size_ = size;
		cap_ = init_l.size();
		capacity_ = cap_;
		data_ = new T[capacity_];
		size_t indx = 0;
		top1_ = -1;
		top2_ = -1;
		
		for (auto s : init_l){
			data_[indx++] = s;
			top1_++;
		} //of for
		
	}; //of constructor 2
	
	/*
	The purpose of this constructor is to copy all of the values of a BiStack
	object to another. They are not connected after the copy, and stand as two
	different objects.
	*/	
	BiStack(BiStack<T>& b){
	
		capacity_ = b.capacity_;
		size_ = b.size_;
		cap_ = b.cap_;
		data_ = new T[capacity_];
		top1_ = b.top1_;
		top2_ = b.top2_;
		copy(b.data_,b.data_+b.cap_,data_);
				
	}; //of copy constructor

	/*
	The purpose of this destructor is to remove the allocated memory after it is 
	no longer in use.
	*/	
	~BiStack(){
	
		if (data_){
			delete[] data_;
		} //of if 
		
	}; //of destructor

	/*
	The purpose of this member function is to return the current allowed 
	capacity of the BiStack object. 
	*/	
	size_t capacity(){
		return capacity_;
	} //of capacity 

	/*
	The purpose of this member function is to return the current number of
	elements that are in the BiStack object.
	*/	
	size_t size(){
		return cap_;
	} //of size 

	/*
	The purpose of this member function is to return the max allowable size for
	the BiStack object to grow to.
	*/	
	size_t max(){
		return size_;
	} //of max

	/*
	The purpose of this equal constructor is to create a BiStack object that
	is referenced to the input BiStack object. If one of the objects changes,
	so does the other one.
	*/	
	BiStack<T>& operator=(BiStack<T>& b){
	
		capacity_ = b.capacity_;
		size_ = b.size_;
		cap_ = b.cap_;
		data_ = new T[capacity_];
		top1_ = b.top1_;
		top2_ = b.top2_;
		copy(b.data_,b.data_+b.cap_,data_);
		
		return *this;	
		
	} //of operator = 

	/*
	The purpose of this member function is to add an element to the end of
	Stack 1 and	grow the array size if necessary.
	*/	
	void push1(T p1){
	
		if (cap_ == capacity_){
		
			grow_and_copy();
		
		} //of if
		
		data_[top1_+1] = p1;
		top1_++;
		cap_ ++;
		
	} //of push1

	/*
	The purpose of this member function is to add an element to the end of
	Stack 2 and	grow the array size if necessary.
	*/	
	void push2(T p2){
	
		if (cap_ == capacity_){
		
			grow_and_copy();
			data_[capacity_-1] = p2;
			top2_ = capacity_ - 1;
			cap_++;
			
		} //of if	
		
		else{
		
			data_[cap_] = p2;
			top2_ = top1_+1;
			cap_++;
					
		} //of else
		
	} //of push2

	/*
	The purpose of this member function is to return the top element of Stack 1.
	If Stack 1 is empty, it throws an underflow error.
	*/	
	T top1(){
	
		string err = "underflow stack 1";
		
		if(!empty1()){
			return data_[top1_];
		} //of if
		
		else{
			throw underflow_error(err);
		} //of else
		
	} //of top1

	/*
	The purpose of this member function is to return the top element of Stack 2.
	If Stack 2 is empty, it throws an underflow error.	
	*/	
	T top2(){
	
		string err = "underflow stack 2";
		
		if(!empty2()){
			return data_[top2_];
		} //of if
		
		else{
			throw underflow_error(err);
		} //of else
	
	} //of top2

	/*
	The purpose of this member function is to remove the last element in 
	Stack 1. If Stack 1 is empty, it throws an underflow error.
	*/	
	void pop1(){
	
		string err = "underflow stack 1";
	
		if(!empty1()){
			top1_--;
			cap_--;
		} //of if 
		
		else{
			throw underflow_error(err);
		} //of else
	
	} //of pop1

	/*
	The purpose of this member function is to remove the last element in 
	Stack 2. If Stack 2 is empty, it throws an underflow error.	
	*/	
	void pop2(){
	
		string err = "underflow stack 2";
	
		if(!empty2()){
			top2_--;
			cap_--;
		} //of if 
		
		else{
			throw underflow_error(err);
		} //of else
	
	} //of pop2

	/*
	The purpose of this function is to return the boolean of whether Stack 1
	contains any elements or not.
	*/	
	bool empty1(){
	
		if (top1_ == -1){
			return true;
		} //of if
		
		else{
			return false;
		} //of else
		
	} //of empty1

	/*
	The purpose of this function is to return the boolean of whether Stack 2
	contains any elements or not.	
	*/	
	bool empty2(){
	
		if (top2_ == -1){
			return true;
		} //of if
		
		else{
			return false;
		} //of else	
		
	} //of empty2

	/*
	The purpose of this friend function is to print out the various BiStack
	variables to an ostream. The elements in the array are printed out
	as well, using an ostringstream and separating each element by a comma. The 
	ostream is returned.
	*/	
	friend ostream& operator<<(ostream& o, const BiStack<T>& b){
		
		string str;
		string temp;
		ostringstream ss;
		
		if (b.top1_ == -1){
			o << "Top1 empty" << endl;
		} //of if
		
		else{
			o << "Top1 index:" << b.top1_ << endl;
		} //of else
		
		if (b.top2_ == -1){
			o << "Top2 empty" << endl;
		} //of if
		
		else{
			o << "Top2 index:" << b.top2_ << endl;
		} //of else	
		
		o << "Size:" << b.cap_ << endl;
		o << "Capacity:" << b.capacity_ << endl;
		
		if (b.top2_ == -1){
		
			for (unsigned int i = 0; i < b.capacity_; i++){
				
				ss << b.data_[i];
				temp = ss.str();
				str += temp + ",";
				ss.str("");	
				ss.clear();			

			} //of for
		} //of if
		
		else{
			for (int i = 0; i < b.top2_; i++){
			
				ss << b.data_[i];
				temp = ss.str();
				str += temp + ",";
				ss.str("");				
				ss.clear();	
				
			} //of for
			
			for (auto i = b.capacity_ - 1; i >= b.top2_; i--){

				ss << b.data_[i];
				temp = ss.str();
				str += temp + ",";
				ss.str("");					
				ss.clear();	
				
			} //of for
		} //of else
		
		str = str.substr(0, str.length()-1);
		o << str;
		
    	return o;
    	
	}; //of friend function operator<<
}; //of vector class

#endif
