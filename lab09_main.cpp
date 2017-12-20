#include<iostream>
#include<string>

using std::cout; using std::endl;
using std::string;

#include "lab09_vector.h"

int main (){
  long scalar=20;
  MathVector v1;

  MathVector v2(3,2);

  long long_result;
  double dbl_result;
  MathVector vec_result;

  cout <<"V1:"<<vec_to_str(v1)<<", V2:"<<vec_to_str(v2)<<endl;
  vec_result = v1.add(v2);
  cout <<"Sum of v1 and v2 is: "<<vec_to_str(vec_result)<<endl;
  vec_result = v2.mult(20);
  cout <<"mult of v2 and "<< scalar <<" is: "<<vec_to_str(vec_result)<<endl;
  long_result = v1.mult(v2);
  cout <<"mult of v1 and v2 is: "<< long_result <<endl;
  dbl_result = v2.magnitude();
  cout <<"magnitude of v2 is: "<< dbl_result <<endl;  
}
