#include<iostream>
using std::cout; using std::endl;
#include<iomanip>
using std::setw;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;

template<typename T>
using matrix_row = vector<T>;

template<typename T>
using matrix = vector<matrix_row<T>>;

/* 
nicely print a matrix. Should have row/column alignment
converts it to a string (doesn't print to cout!!!)
uses width to space elements (setw). Default is 3
*/
template<typename T>
string matrix_to_str(const matrix<T> &m1, size_t width=3)
{
	string s;
	ostringstream oss; 
	for(auto r : m1)
	{
		for(auto k : r)
		{
			oss << setw(width) << k << "   "; 
		}
		oss << endl;	
	}
	s = oss.str();
	return s;
}

/*
true if the two matrices have the same shape
false otherwise
*/
template<typename T>
bool same_size(matrix<T>& m1, matrix<T>& m2)
{
	bool same = true;
	if(m1.size()== m2.size())
	{
		for(unsigned int i = 0; i < m1.size(); ++i)
		{
			if(m1[i].size() != m2[i].size())
			{
				same = false;
				break;
			}
		}
	}
	else
		same = false;
		
	return same;
}

/*
matrices must not be empty and must be the same shape:
- if true, return a new matrix that adds m1+m2
- if false, return an empty matrix (no elements)
*/
template<typename T>
matrix<T> add(matrix<T>& m1, matrix<T>& m2)
{
	matrix<T> madd;
	matrix_row<T> temp;
	unsigned int mrsize = m1.size();
	if(same_size(m1,m2))
	{
		for(unsigned int i = 0; i < mrsize; ++i)
		{
		unsigned int mcsize = m1[i].size();
			for(unsigned int j = 0; j < mcsize; ++j)
			{
				unsigned int mij1 = m1[i][j];
				unsigned int mij2 = m2[i][j];
				temp.resize(mcsize);
				temp.at(j)= mij1 + mij2;
			}
			madd.push_back(temp);
		}
	}
	return madd;
}

 
/*matrix must not be empty:
- if true, multiply T scalar value by m
- if false, return empty matrix (no elements)
*/
template<typename T>
matrix<T> scalar_multiply(matrix<T> &m, T val)
{
	matrix<T> madd;
	matrix_row<T> temp;
	unsigned int mrsize = m.size();
	for(unsigned int i = 0; i < mrsize; ++i)
	{
	unsigned int mcsize = m[i].size();
		for(unsigned int j = 0; j < mcsize; ++j)
		{
			unsigned int mij = (m[i][j]) * val;
			temp.resize(mcsize);
			temp.at(j)= mij;
		}
		madd.push_back(temp);
	}
	return madd;
}
    
int main(){
  matrix<long> m1{ {0,1,2}, {3,4,5}, {6,7,8} };
  matrix<long> m2{ {0,1}, {2,3}, {4,5} };
  matrix<long> m3;
  matrix<long> result;
  

  // case 1
  result = add(m1,m1);
  if (! result.empty() )
    cout << matrix_to_str(result) << endl;
  else
    cout << "could not add" << endl;

  // case 2
  result = add(m1, m2);
  if (! result.empty() )
    cout << matrix_to_str(result) << endl;
  else
    cout << "could not add" << endl;

  // case 3
  result = scalar_multiply(m1,3l);
   if (! result.empty() )
    cout << matrix_to_str(result) << endl;
   else
    cout << "could not multiply" << endl;

  // case 4
  result = scalar_multiply(m3,3l);
   if (! result.empty() )
    cout << matrix_to_str(result) << endl;
  else
    cout << "could not multiply" << endl;
}
