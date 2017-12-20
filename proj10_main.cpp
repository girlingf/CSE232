#include<iostream>
using std::cout; using std::cin; using std::endl;
using std::boolalpha;
#include<stdexcept>
using std::overflow_error; using std::underflow_error;
#include<string>
using std::string;


#include "proj10_class-10.h"

int main (){
  int test_no;
  cin >> test_no;
  cout << boolalpha;

  switch(test_no){

  case 1: {
    BiStack<long> b;
    cout << b.capacity() << endl;
    cout << b.size() << endl;
    cout << b.max() << endl;
    break;
  }

  case 2:{
    BiStack<long> b{1,2,3,4,5,6};
    cout << b.capacity() << endl;
    cout << b.size() << endl;
    cout << b.max() << endl;
    break;
  }

  case 3:{
    BiStack<long> b{1,2,3,4,5,6};
    cout << b << endl;
    break;
  }

  case 4:{
    BiStack<long> b{1,2,3,4,5,6};
    cout << b.empty1() << endl;
    cout << b.empty2() << endl;
    break;
  }
    
  case 5:{
    BiStack<long> b{1,2,3,4,5,6};
    b.push2(200);
    b.push1(100);
    cout << b << endl;
    break;
  }

  case 6:{
    BiStack<long> b{1,2,3,4,5,6};
    b.push2(200);
    b.push1(100);
    cout << b.top1() << endl;
    cout << b.top2() << endl;
    break;
  }

  case 7:{
    BiStack<long> b{1,2,3,4,5,6};
    try{
      cout << b.top1() << endl;
      cout << b.top2() << endl; // should throw
    }
    catch (underflow_error &e){
      cout << e.what() << endl;
    }
    break;
  }

  case 8:{
    BiStack<long> b{1,2,3,4,5,6};
    try{
      b.pop1();
      cout << b << endl;
      b.pop2(); // should throw
    }
     catch (underflow_error &e){
      cout << e.what() << endl;
    }
    break;
  }

  case 9:{
    BiStack<long> b1{1,2,3,4,5,6};
    BiStack<long> b2(b1);
    b1.push1(100);
    b2.push2(200);
    cout << b1 << endl;
    cout << b2 << endl;
    break;
  }

  case 10:{
    BiStack<long> b1{1,2,3,4,5,6};
    BiStack<long> b2;
    b2 = b1;
    b1.push1(100);
    b2.push2(200);
    cout << b1 << endl;
    cout << b2 << endl;
    break;
  }

  case 11:{
    BiStack<string> b(4);
    b.push1("a");
    b.push1("b");
    b.push2("y");
    b.push2("z");    
    cout << b << endl;
    for (int i=0; i< 5; ++i)
      b.push1(string(1,'h'+i));
    cout << b << endl;
    break;
  }

  case 12:{
    BiStack<string> b(4,8);
    b.push1("a");
    b.push1("b");
    b.push2("y");
    b.push2("z");  
    cout << b << endl;

    // loop should exceed max and throw
    try{
      for (int i=0; i< 5; ++i)
	b.push1(string(1,'h'+i));
      cout << b << endl;
    }
    catch(overflow_error &e){
      cout << e.what() << endl;
    }
    break;
  }
    
  }
}
      
