#include <iostream>
#include <vector>
using std::cout;using std::cin;using std::endl;
using std::vector; using std::stoi;
#include<string>
using std::string;
#include<algorithm>
using std::remove;
#include<sstream>
using std::stringstream;
#include "proj06_functions.h"

/*
CSE232 Section 001
3/10/17
Project 06
*/

/*
The purpose of this function is to create a 2d vector containing 1's and 0's
read from the input file. It takes an integer for number of columns and number
of rows to determine how large the 2d vector is. It returns the 2d vector.
*/
vector<vector<int>> readImage(int col, int r){

	using TableRow = vector<int>;
	using Table = vector<TableRow>;
	
	TableRow rows;
	Table board;

	string temp;
	
	while (cin != NULL){
	
		getline(cin, temp, '\n');
		temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
		
		for (unsigned int x = 0; temp[x]; ++x){
			//int int_dec = stoi(temp[x]);
			//cout << temp[x] << endl;
			rows.push_back(temp[x]-48);
			rows.erase(remove(rows.begin(), rows.end(), -35), rows.end());
		} //of for
		
		board.push_back(rows);
		rows.clear();

	} //of while
	
	return board;
} //of readImage

/*
The purpose of this function is to print the 2d vector created by the function 
readImage. The function iterates through the rows and columns and prints out
the vector as it looked in the input file. It returns nothing but prints
the vector to the terminal.
*/
void printImage(vector<vector<int>> vect){
	
	for (auto r : vect){
	
		for (auto k : r){
		
			cout << k;
			
		} //of for
		
		cout << endl;
		
	} //of for
} //of printImage

/*
The purpose of this function is to count the number of holes in the image from
the input file. This is done by looking at 2x2 grids on the 2d vector and
finding how many e and i values there are. Those values are then used to 
calculate the number of holes. The function returns the number of holes.
*/
int countHoles(vector<vector<int>> vect){

	int holes, e, i;
	//cout << vect.size() << endl;
	for (unsigned int j = 0; vect[j].size()-1; ++j){
		//cout << "test" << endl
		for (unsigned int k = 0; k == 1; ++k){
			cout << "test" << endl;
			if (vect[j+1][k+1]){
				if ((vect[j][k] + vect[j+1][k] + vect[j][k+1] + vect[j+1][k+1]) == 3){
					e += 1;
				} //of if
				else if ((vect[j][k] + vect[j+1][k] + vect[j][k+1] + vect[j+1][k+1]) == 0){
					i += 1;
				} //of if
				
			
			} //of if
		} //of for
	} //of for
	
	holes = (e - i)/4;
	
	return holes;
} //of countHoles
