#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;
#include<typeinfo>

#include "lab13_singlelink.h"

int main () {

  SingleLink<string>sl;
  sl.append_back("beds");
  sl.append_back("tables");
  cout << sl << endl;
  
  sl.append_back("chairs");
  cout << sl << endl;

  sl.del("tables");
  cout << sl << endl;

  sl.append_back("beds");
  cout << sl << endl;

  sl.del("chairs");
  cout << sl << endl;

	cout << sl[1].data_ << endl;
	string s =  sl[1].data_;
  
  sl.append_back(s);
  cout << sl << endl;
}
