#include<iostream>
using std::cout; using std::endl; using std::boolalpha;
#include<stdexcept>
using std::out_of_range;

#include "lab10_table.h"

int main (){
  bool result_bool;
  long result_long;
  cout << boolalpha;
  
  Table my_table(5,5);
  cout << my_table << endl;;

  my_table.fill_random(1,10);
  cout << my_table << endl;

  result_bool = my_table.set_value(100,100,100);
  cout << "Result:"<<result_bool<<endl;
  cout << endl;

  try{
    result_long = my_table.get_value(3,3);
    cout << result_long << endl;

    // should trhow
    result_long = my_table.get_value(100,100);
    cout << result_long << endl;
    cout << endl;
  }
  catch (out_of_range &e){
    cout << e.what() << endl << endl;
  }
  
  
  for(int i=0; i< 5; i++)
    my_table.set_value(i,i,100);

  cout << my_table << endl;
}
