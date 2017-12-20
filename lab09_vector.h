#ifndef vector_h
#define	vector_h

#include<iostream>
#include<string>
using std::cout; using std::endl;
using std::string;

struct MathVector{
	long x;
	long y;
	
	MathVector();
	MathVector(long, long);
	
	MathVector add(const MathVector&);
	MathVector mult(long);
	long mult(const MathVector&);
	double magnitude();
}; //of MathVector

string vec_to_str(const MathVector&);

#endif	/* vector_h */
