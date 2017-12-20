#ifndef PAL_H
#define PAL_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<utility>
using std::swap;
#include<sstream>
using std::ostringstream;
#include<string>
using std::string; using std::to_string;
#include<utility>
using std::pair;
#include<iomanip>

/*
CSE232 Section 001
4/21/17
Project 11
*/

template<typename T>
class PAL;

//node class
template <typename T>
class Element{
private:
  Element *next_ = nullptr;
  string name_ = "";
  T color_ = T();
  
public:
  Element()=default;
  Element(string name, T d) : next_(nullptr), name_(name), color_(d){};
  friend ostream& operator<<(ostream& out, Element& n){

	out << n.name_ << ":" << n.color_;
	
	return out;
    
  } //of operator <<
  friend class PAL<T>;
}; //of Element class


template<typename T>
class PAL{
private:
  Element<T> *back_ = nullptr; //first in list, drawn first (in back)
  Element<T> *front_ = nullptr; //last in list, drawn last (in front)
  void print_list(ostream& out){
  
  	ostringstream o;
  	Element<T>* ptr;
  	
  	for (ptr = back_; ptr != nullptr; ptr = ptr->next_){
  		o << *ptr << ", ";
  	} //of for 
  	
  	string str = o.str();
  	
  	out << str.substr(0,str.size()-2);

  } //of print_list 
public:
  PAL()=default;
  PAL(Element<T> n) : back_(&n), front_(&n) {};
  PAL(string n, T d);
  PAL(const PAL&);
  PAL& operator=(PAL);
  ~PAL();
  void add(Element<T> &n);
  void add(string name, T dat);
  void add_back(Element<T> &n);
  void add_back(string name, T d);
  pair<Element<T>*, Element<T>*> find(string name);    
  pair<Element<T>*, Element<T>*> find(Element<T> &n);
  bool front(Element<T> n);
  bool back(Element<T> n);
  Element<T>* get_prev(Element<T>* head, Element<T>* a);
  void swap_e(Element<T>** head, Element<T>** a, Element<T>** b);
  void move_forward1(Element<T> &n);
  void move_to_front(Element<T> &n);  
  void move_back1(Element<T> &n);
  void move_to_back(Element<T> &n);  

  friend ostream& operator<<(ostream& out, PAL<T>& sl){
    sl.print_list(out);
    return out;
  };
}; //of PAL class

/*
This is a PAL class constructor, it creates a PAL object.
*/
template<typename T>
PAL<T>::PAL(string n, T d){
	Element<T>* ptr = new Element<T>(n, d);
	back_ = ptr;
	front_ = ptr;
}; //of constructor

/*
This is the PAL class copy constructor. It creates a copy of a PAL object.
*/
template<typename T>
PAL<T>::PAL(const PAL& p){

	if (p.back_ == nullptr){
	
		back_ = nullptr;
		front_ = nullptr;
		
	} //of if 
	
	else{
		back_ = new Element<T>(p.back_->name_, p.back_->color_);
		front_ = back_;
		Element<T>* p_ptr = p.back_->next_;
		Element<T>* new_element;
		
		while (p_ptr != nullptr){
		
			new_element = new Element<T>(p_ptr->name_, p_ptr->color_);
			front_->next_ = new_element;
			p_ptr = p_ptr->next_;
			front_ = new_element;
		} //of while
	} //of else
}; //of constructor

/*
This function sets a newly created PAL object equal to the RHS PAL object.
*/
template<typename T>
PAL<T>& PAL<T>::operator=(PAL p){

	swap(back_, p.back_);
	swap(front_, p.front_);
	return *this;
	
}; //of operator ==

/*
This is the destructor for the PAL class. It deletes allocated memory that is 
no longer needed.
*/
template<typename T>
PAL<T>::~PAL(){

	Element<T>* to_del = back_;
	
	while (to_del != nullptr){
	
		back_ = back_->next_;
		delete to_del;
		to_del = back_;
		
	} //of while
	
	back_ = nullptr;
	front_ = nullptr;
	
}; //of destructor

/*
This member function adds an element to the front of the PAL list.
*/
template<typename T>
void PAL<T>::add(Element<T>& n){
	
	if (back_ != nullptr){
	
		n.next_ = back_;
		back_ = &n;
		
	} //of if
	
	else{
	
		back_ = &n;
		front_ = &n;
		
	} //of else
}; //of add

/*
This member function creates a new element and adds it to an empty list.
*/
template<typename T>
void PAL<T>::add(string name, T d){

	Element<T>* n = new Element<T>(name, d);
	add(*n);
	
}; //of add

/*
This member function adds an element to the back of the PAL list.
*/
template<typename T>
void PAL<T>::add_back(Element<T> &n){
	
	if (front_ != nullptr){

		front_->next_ = &n;
		front_ = &n;

	} //of if 
	
	else{
	
		back_ = &n;
		front_ = &n;

	} //of else
	
} //of add_back

/*
This member function creates a new Element and adds it to an empty list.
*/
template<typename T>
void PAL<T>::add_back(string name, T d){

	Element<T>* n = new Element<T>(name, d);
	add_back(*n);
	
} //of add_back

/*
This member function finds if an element already exists.
*/
template<typename T>
pair<Element<T>*, Element<T>*> PAL<T>::find(string name){

	pair<Element<T>*, Element<T>*> result(nullptr, nullptr);

	for (Element<T> *i = back_; i != nullptr; i = i->next_){

		if (i->name_ == name){
		
			result.first = i;
			break;
			
		} //of if
		
		result.second = i;
		
	} //of for 
	
	return result;
	
}; //of find 

/*
This member function finds if an element already exists.
*/
template<typename T>
pair<Element<T>*, Element<T>*> PAL<T>::find(Element<T> &n){

	pair<Element<T>*, Element<T>*> result(nullptr, nullptr);
	
	for (Element<T> *i = back_; i != nullptr; i = i->next_){
		
		if (i->color_ == n.color_){
		
			result.first = i;
			break;
			
		} //of if
		
		result.second = i;
		
	} //of for
	 
	return result;
	
}; //of find

/*
This member function determines if a given element is the last item in the list.
*/
template<typename T>
bool PAL<T>::front(Element<T> n){

	if (n.color_ == front_->color_){
		return true;
	} //of if 
	
	else{
		return false;
	} //of else
	
}; //of front 

/*
This member function determines if a given element is the first item in the
list.
*/
template<typename T>
bool PAL<T>::back(Element<T> n){

	if (n.color_ == back_->color_){
		return true;
	} //of if 
	
	else{
		return false;
	} //of else
	
}; //of back

/*
This member function grabs the previous node in the list.
*/
template<typename T>
Element<T>* PAL<T>::get_prev(Element<T>* head, Element<T>* a){

	Element<T>* ptr = nullptr;
	Element<T>* temp = head;
	
	if (head == a){
		return ptr;
	} //of if 
	
	while (temp && temp != a){
		ptr = temp;
		temp = temp->next_;
	} //of while
	
	return ptr;
	
}; //of get_prev

/*
This member function swaps two elements in the list.
*/
template<typename T>
void PAL<T>::swap_e(Element<T>** head, Element<T>** a, Element<T>** b){

	Element<T>* temp = get_prev(*head, *a);
	Element<T>* temp2 = get_prev(*head, *b);
	Element<T>* temp3 = nullptr;
	
	if (temp){
		temp->next_ = (*b);
	} //of if 
	
	if (temp2){
		temp2->next_ = (*a);
	} //of if 
	
	temp3 = (*a)->next_;
	(*a)->next_ = (*b)->next_;
	(*b)->next_ = temp3;
	
	if ((*head) == (*a)){
		*head = *b;
	} //of if 
	
	if ((*head) == (*b)){
		*head = *a;
	} //of if
	
} //of swap_e

/*
This member function moves a given element forward 1 spot in the list.
*/
template<typename T>
void PAL<T>::move_forward1(Element<T> &n){
	
	/*if (find(n).first->color_ == n.color_){
		if (!front(n)){
			for (Element<T> *i = back_; i != nullptr; i = i->next_){
		
				if (i->color_ == n.color_){
				
					swap_e(&back_, &i, &i->next_);
					
					if (front(*i)){

						i = &n;
						front_ = i;
						
					} //of if
					
					break;
					
				} //of if
				//temp = i->next_;
			} //of for 
		} //of if 
	} //of if*/
	
	Element<T>* temp;
	
	if (find(n).first->color_ == n.color_){
		if (!front(n)){
			for (Element<T> *i = back_; i != nullptr; i = i->next_){
		
				if (i->color_ == n.color_){
				
					temp = i->next_;
					swap(n, *temp);
					
					if (front(*temp)){
						front_ = &n;
					} //of if

					add_back(temp->name_, temp->color_);
					
					break;
					
				} //of if 
			} //of for 
		} //of if 
	} //of if 
	 
}; //of move_forward1

/*
This member function moves a given element to the end of the list.
*/
template<typename T>
void PAL<T>::move_to_front(Element<T> &n){

	Element<T>* temp;
	
	if (find(n).first->color_ == n.color_){
		if (!front(n)){
			for (Element<T> *i = back_; i != nullptr; i = i->next_){
		
				if (i->color_ == n.color_){
				
					temp = i->next_;
					swap(n, *temp);
					
					if (front(*temp)){
						front_ = &n;
					} //of if

					add_back(temp->name_, temp->color_);
					
					break;
					
				} //of if 
			} //of for 
		} //of if 
	} //of if 
}; //of move_to_front

/*
This member function moves a given element backward 1 spot in the list.
*/
template<typename T>
void PAL<T>::move_back1(Element<T> &n){

	Element<T>* temp;
	
	if (find(n).first->color_ == n.color_){
		if (!back(n)){
			for (Element<T> *i = back_; i != nullptr; i = i->next_){
		
				if (i->color_ == n.color_){
				
					temp = i->next_;
					swap(n, *temp);
					
					if (back(*temp)){
						front_ = &n;
					} //of if

					add(temp->name_, temp->color_);
					break;
					
				} //of if 
			} //of for 
		} //of if 
	} //of if
}; //of move_back1

/*
This member function moves a given element to the start of the list.
*/
template<typename T>
void PAL<T>::move_to_back(Element<T> &n){

	Element<T>* temp;
	
	if (find(n).first->color_ == n.color_){
		if (!back(n)){
			for (Element<T> *i = back_; i != nullptr; i = i->next_){
		
				if (i->color_ == n.color_){
				
					temp = i->next_;
					swap(n, *temp);
					
					if (back(*temp)){
						front_ = &n;
					} //of if

					add(temp->name_, temp->color_);
					break;
					
				} //of if 
			} //of for 
		} //of if 
	} //of if
}; //of move_to_back

#endif
