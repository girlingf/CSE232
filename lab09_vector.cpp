#include<iostream>
#include<string>
using std::cout; using std::endl;
using std::string;
#include<math.h> 
#include<sstream>
using std::ostringstream;
#include "lab09_vector.h"

//default constructor
MathVector::MathVector(){

}
//constructor of 2 arguments

MathVector::MathVector(long xin, long yin){
	x=xin;
	y=yin;
} //of constructor

MathVector MathVector::add(const MathVector &m){
	MathVector result(x+m.x,y+m.y);
	return result;
} //of add

MathVector MathVector::mult(long n){
	MathVector result(x*n,y*n);
	return result;
} //of mult

long MathVector::mult(const MathVector &m){
	long result = x*m.x + y*m.y;
	return result;
} //of mult

double MathVector::magnitude(){
	double result = sqrt(x*x+y*y);
	return result;
} //of magnitude

string vec_to_str(const MathVector &v){

	ostringstream oss;

	oss << v.x << ":" << v.y <<endl;
	return oss.str();
		
} //of vec_to_str

