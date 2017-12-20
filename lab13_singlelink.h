#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<stdexcept>

template <typename T>
struct Node{
public:
    Node *next_;
    T data_;
    
Node() : data_( T() ), next_(nullptr) {};
Node(T d) : data_(d), next_(nullptr) {};
};

template <typename T>
class SingleLink{
private:
    Node<T> *head_;
    Node<T> *tail_;
  
public:
    SingleLink() : head_(nullptr), tail_(nullptr) {}; // FIX HERE as above in Node
    SingleLink(Node<T> n) : head_(&n), tail_(&n) {}; // FIX HERE as above in Node
    void append_back(T);
    friend ostream& operator<<(ostream &out, SingleLink<T>& s){
      for (auto ptr = s.head_; ptr != nullptr;  ptr = ptr->next_){
      	out << ptr->data_ << ",";
      } //of for
      
      return out;
    };
    bool del(T val);
    Node<T>& operator[](size_t index);

};

// YOUR STUFF HERE
template <typename T>
	void SingleLink<T>::append_back(T app){
		Node<T>* n = new Node<T>(app);
		if (tail_ != nullptr){
			tail_->next_ = n;
			tail_ = n;
		} //of if
		else{
			head_ = n;
			tail_ = n;
		} //of else

	} //of append_back
	
template <typename T>
	bool SingleLink<T>::del(T val){
	
		bool d = false;
		auto last = head_;
	
		for (auto ptr = head_; ptr != nullptr; ptr = ptr->next_){
			
			if (ptr->data_ == val){
				d = true;
				
				if (ptr == head_){
					head_ = ptr->next_;
					delete ptr;
				} //of if 
				
				else if (ptr == tail_){
					tail_ = last;
					delete ptr;
				} //of else if 
				
				break;
				
			} //of if 
			
			last = ptr->next_;
			
		} //of for
		return d;
	} //of del
	
template <typename T>	
	Node<T>& SingleLink<T>::operator[](size_t index){
		
		Node<T>* n = nullptr;
		int j = 0;
		for(auto ptr = head_; ptr != nullptr; ptr = ptr->next_){
			j += 1;
		} //of for

			if (index >= 0 && index < j){	
				n=head_;
				size_t i=0;
				while(i!=index)
				{
					n=n->next_;
					i++;
				}
				return *n;
			}
			return *n;
	} //of operator []




#endif
  
