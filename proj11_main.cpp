#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<string>
using std::string;

#include "proj11.h"

int main (){
  int test_no;
  cin >> test_no;
  
  switch(test_no){

  case 1:{
    PAL<string> p;
    p.add("square", "blue");
    p.add("circle", "green");
    p.add("triangle", "red");
    cout << p << endl;
    break;
  }

  case 2:{
    PAL<string> p("square", "blue");
    p.add("circle", "green");
    p.add("triangle", "red");
    auto pr = p.find("circle");
    cout << *(pr.first) <<" : "<< *(pr.second) << endl;
    break;
  }

  case 3:{
    PAL<string> p("square", "blue");
    p.add("circle", "green");
    p.add("triangle", "red");
    auto pr = p.find("circle");
    cout << *(pr.first) <<" : "<< *(pr.second) << endl;    
    cout << p << endl;
    p.move_forward1(*(pr.first) );
    cout << p << endl;
    break;
  }

  case 4:{
    PAL<string> p("square", "blue");
    p.add("circle", "green");
    p.add("triangle", "red");
    auto pr = p.find("circle");
    cout << *(pr.first) <<" : "<< *(pr.second) << endl;    
    cout << p << endl;
    p.move_back1(*(pr.first) );
    cout << p << endl;
    break;
  }

  case 5:{
    PAL<string> p("square", "blue");
    p.add("circle", "green");
    p.add("triangle", "red");
    auto pr = p.find("circle");;
    cout << *(pr.first) <<" : "<< *(pr.second) << endl;    
    cout << p << endl;
    p.move_to_back(*(pr.first) );
    cout << p << endl;
    break;
  }

  case 6:{
    PAL<string> p("square", "blue");
    p.add("circle", "green");
    p.add("triangle", "red");
    auto pr = p.find("circle");
    cout << *(pr.first) <<" : "<< *(pr.second) << endl;    
    cout << p << endl;
    p.move_to_front(*(pr.first) );
    cout << p << endl;
    break;
  }

  case 7:{
    PAL<long> p("square", 0x0000FF);
    p.add("circle", 0x00FF00);
    p.add("triangle", 0xFF0000);
    PAL<long> p_copy(p);
    p_copy.add("diamond",0xFFFF00);
    PAL<long> p_equal;
    p_equal = p;
    p_equal.add("oval", 0xFF00FF);
    cout << p << endl;
    cout << p_copy << endl;
    cout << p_equal << endl;
    break;
  }
    
  }
}
