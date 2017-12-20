#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<iomanip>
using std::boolalpha;
#include<string>
using std::string;
#include<stdexcept>
using std::runtime_error;

#include "lab11_circbuf.h"

int main(){
  const size_t sz = 4;
  CircBuf cb(sz);

  cout << boolalpha;
  cb.add(1);
  cb.add(2);

  cout << "Front:"<<cb.front()<<endl;
  cout << "Back:"<<cb.back() << endl;
  cout << cb << endl;

  cb.remove();
  cout << "Front:"<<cb.front() <<endl;
  cb.remove();
  cout << "Empty?:"<<cb.empty() << endl;
  cout << cb << endl;

  cout << "Add 4 elements"<<endl;
  for(long i=0; i<4;i++)
    cb.add(i+27);
  cout << cb << endl;

  cout << "Remove 4 elements"<<endl;
  while(!cb.empty()){
    cout << cb.front() << ", ";
    cb.remove();
  }

  cout << "Fill er up"<<endl;
  for(int i=0; !cb.full(); i++)
    cb.add(i*i);
  cout << "Full?:"<<cb.full() <<endl;

  cout << "Drain it"<<endl;
  for(int i=0; !cb.empty(); i++)
    cb.remove();  
  cout << "Empty?:"<<cb.empty()<<endl;

  try{
    cout << cb.front() << endl;
  }
  catch (runtime_error err){
    cout << "Yo, cannot access an empty buffer. Real error msg follows"<<endl;
    cout << err.what() << endl;
  }

}
