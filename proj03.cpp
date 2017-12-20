#include<iostream>
#include<math.h>

/*
CSE232 Section 001
2/4/17
Project 03
*/

using std::cout; using std::cin; using std::endl;
using std::boolalpha;


/*
The purpose of this function is to determine if an input integer is a prime
number. If the integer is prime, it returns the boolean true. If it is not,
the function returns the boolean false.
*/
bool is_prime (long n){
	
	if (n < 2) //a number < 2 cannot be prime
		return false;
		
	if (n == 2) //2 is a prime number
		return true;
		
	if (n%2 == 0) //if it is divisible by 2 with no remainder, it isn't prime
		return false;
		
	//checking if the number can be divided with no remainder
	for (int i = 3; (i*i) <= n; i += 2){
		if (n%i == 0) //no remainder
			return false;
			break;
	} //of for
	return true;
} //of is_prime

/*
The purpose of this function is to determine if an input integer is a powerful
number or not. It calls the above is_prime function. If the integer is a
powerful number, it will return the boolean true. If it is not, the function
will return the boolean false.
*/
bool is_powerful (long n){
	//call the is_prime function
	bool prime = is_prime(n);
	
	//prime numbers can't be powerful numbers
	if (prime == true)
		return false;
		
	for (int i = 2; n-1; i++){
		if (n%i == 0){ //no remainder
		
			if (n%(i*i) == 0) //no remainder if i is squared
				return true;
				
			else
				return false;
		} //of if
		else
			return false;
	} //of for
	return true;
} //of is_powerful

/*
The purpose of this function is to determine if an input integer is a perfect
power or not. It uses a while loop nested within a for loop to iterate over
all of the checks needed. If the integer is a perfect power, it returns the
boolean true. If it is not, the function returns the boolean false.
*/
bool is_perfect_power (long n){
	//this is the base number, x, for x to the power of y
	for (int i = 2; i <= pow(n,0.5); i++){
		

		int j = 2; //iterative number, y
		long power = pow(i,j); //pow sets 1st input to the power of 2nd input
		
		while (power <= n && j > 0){
			if (power == n)
				return true;
			j++; //increase j by 1
			power = pow(i,j); //calculate new value for power
			
		} //of for
	} //of for
	return false;
} //of is_perfect_power

/*
The purpose of this function is to determine if an input integer n is an
achilles number or not. It calls the functions is_powerful and is_perfect_power.
If is_powerful returns true and is_perfect_power returns false, then the boolean
value of true is returned. Otherwise, the function will return the boolean value
of false.
*/
bool is_achilles (long n){
	
	bool powerful = is_powerful(n); //call is_powerful
	bool perfect_power = is_perfect_power(n); //call is_perfect_power
	
	if (powerful == true && perfect_power == false) //only condition to be true
		return true;
		
	else //all other conditions
		return false;
} //of is_achilles

// main is below. You cannot modify main
int main (){
  cout << boolalpha;

  int test_case;
  cin >> test_case;

  switch (test_case){

  case 1 : {
    long num;
    while (cin >> num)
      cout << num << ":" << is_prime(num) << endl;
    break;
  } // of case 1

  case 2 : {
    long num;
    while (cin >> num)
      cout << num << ":" << is_powerful(num) << endl;
    break;
  } // of case 2

  case 3 : {
    long num;
    while (cin >> num)
      cout << num << ":" << is_perfect_power(num) << endl;
    break;
  } // of case 3   

  case 4 : {
    long num;
    while (cin >> num)
      cout << num << ":" << is_achilles(num) << endl;
    break;
  } // of case 4
    
  } // of switch
} // of main
