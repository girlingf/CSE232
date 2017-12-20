#ifndef vector_h
#define vector_h

#include<iostream>
using std::ostream;
#include<fstream>
using std::ifstream;
#include<map>
using std::map;
#include<string>
using std::string;
#include<stdexcept>
using std::range_error;
#include<algorithm>
using std::swap;
using std::copy;

namespace student {

	template<typename T>
	
	class vector{
	
	private:
		T *data_;
		size_t capacity_;
		size_t size_; 
	
	public:
		vector(){

			capacity_ = 10;
			size_ = 0;
			data_ = new T[capacity_];
			
		}; //of constructor
		
		vector(size_t capacity ){

			capacity_ = capacity;
			size_ = 0;
			data_ = new T[capacity_];
			
		}; //of constructor
		
		~vector(){
			if (data_){
				delete[] data_;
			} //of if 
		}; //of destructor
		
		size_t capacity(){
			return capacity_;
		} //of capacity 
		
		size_t size(){
			return size_;
		} //of size
		
		void push_back(T val){
		
			T *new_data;
			
			if ((size_ + 1) > capacity_){
			
				new_data = new T[2*capacity_];
				
				for (unsigned int i = 0; i < size_ + 1; ++i){
				
					swap(data_[i], new_data[i]);
					
				} //of for
				
				delete [] data_;
				data_ = new_data;
				capacity_ = 2*capacity_;
				data_[size_] = val;
				size_ = size_ + 1;
				
			} //of if
			
			else{
				data_[size_] = val;
				size_ = size_ + 1;
			} //of else
		} //of push_back
		
		T& operator [](size_t val){
			
			string err = "Out of range";
			
			if (val <= size_ || val < 0){
				return data_[val];
			} //of if
			
			else{
				throw range_error(err);
			} //of else
		} //of operator []
		
		T& front(){
		
			string err = "Error!";
			
			if (size_ == 0){
				throw range_error(err);
			} //of if
			
			else{
				return data_[0];			
			} //of else

		} //of front
		
		T& back(){
			
			string err = "Error!";
		
			if (size_ == 0){
				throw range_error(err);
			} //of if
			
			else{
				return data_[(size_-1)];			
			} //of else			
	
		} //of back
		
		vector(vector<T>& v){
			
			capacity_ = v.capacity_;
			size_ = v.size_;
			data_ = new T[capacity_];
			copy(v.data_,v.data_+v.size_,data_);
			
		} //of copy constructor 
		
		vector<T>& operator=(vector<T>&  v){
		
			capacity_ = v.capacity_;
			size_ = v.size_;
			data_ = new T[capacity_];
			copy(v.data_,v.data_+v.size_,data_);
			return *this;
			
		} //of operator =
		
		T& clear(){
		
			capacity_ = 0;
			size_ = 0;
			delete []data_;
			
		} //of clear
		
		//T pop_back(){
		
			
		
		//} //of pop_back
		
	
	}; //of vector class
	
} //of student namespace



#endif
