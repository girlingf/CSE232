#include <iostream>

/*
CSE232 Section 001
1/29/17
Project 02
*/

using std::cin;
using std::cout;
using std::endl;

/*
The purpose of this function is to find the greatest common divisor of two
integers greater than or equal to 1. The two inputs are the values used. The 
GCD is found using Euclid's Algorithm. The GCD is the largest number that
divides both of the 2 integers without leaving a remainder. This function
returns the GCD as an integer.
*/
long gcd(long gcd1, long gcd2){
	//continue looping until the remainder is zero
	while (gcd2 != 0){
	
		long numb = gcd2;
		gcd2 = gcd1 % gcd2; //find the remainder of the current and prev. term
		gcd1 = numb;
	}
	return gcd1;
}

/*
The purpose of this function is to determine how many totatives exist between 
1 and an input integer. A count is initiated and whenever a totative is
encountered, the count value is raised by 1. For each totative reached, it is
output along with a space. All totatives are output on a single line, followed
by the totative count on the next line.
*/
long phi(long input_number){

	long totative_count = 0; //initialize a count, set to 0
	//iterate through each value, 1 to the input, increasing by 1 each time
    for (int i=1; i<=input_number; i++){
    	
    	long gcd_func = gcd(input_number, i); //call the gcd function
    	
        if (gcd_func == 1){
        	cout << i << " "; //output each value that is a totative + a space
            totative_count++; //increase the count by 1
        }
    }
    cout << endl; //end the line that is currently being output to
    return totative_count;
}

/*
The purpose of this function is to take 3 input integers from a file and set
them to 3 variables. Based on the value of the first 2 variables, the smaller
is set to gcd1, and the larger is set to gcd2. The functions gcd and phi are
called, and their return values are output.
*/
int main(){

	long input1, input2, input3; //initial variables to store inputs
	long gcd1, gcd2; //initialize variables that will change input1-3
	
	cin >> input1 >> input2 >> input3; //read 3 inputs from the input file
	
	//if any inputs are less than 1, print "Error" and end the program
	if (input1 < 1 || input2 < 1 || input3 < 1)
		cout << "Error" << endl;
		
	else{
		//order of gcd1 and gcd2 matters, so set gcd1 to the smallest value
		if (input1 < input2){
			gcd1 = input1;
			gcd2 = input2;
		}
		else{
			gcd1 = input2;
			gcd2 = input1;
		}
		//set the gcd function to the variable gcd_var
		long gcd_var = gcd(gcd1,gcd2);
		//output the return value of the function gcp
		cout << gcd_var << endl;
		//set the phi function to the variable phi_var
		long phi_var = phi(input3);
		//output the return value of the function phi
		cout << phi_var << endl;
	}
}

