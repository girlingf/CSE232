#include<iostream>
using std::cout; using std::cin; using std::endl;
using std::boolalpha;
#include<cmath>
using std::sqrt; using std::ceil; using std::round;
#include<string>
using std::string; using std::stol; using std::to_string;
/*
CSE232 Section 001
2/11/17
Project 04
*/

/*
The purpose of this function is to determine if an input integer is a prime
number. If the integer is prime, it returns the boolean true. If it is not,
the function returns the boolean false.
*/
bool is_prime(long n){

	if (n <= 1) //an integer < 1 can't be prime
		return false;
		
	else if (n <= 3) //2 and 3 are prime numbers
		return true;
		
	else if (n%2 == 0 || n%3 == 0) //if divisible by 2 or 3 it isn't prime
		return false;
		
	long i = 5; //initialize divisor
	
	while (i <= pow(n,0.5)){ //while divisor is less than sqrt(input)
		if (n%i == 0 || n%(i+2) == 0){
			return false;
			break; //break to stop iterating
		} //of if
		i += 6;
	} //of while
	
	return true;

} //of is_prime

/*
The purpose of this function is to determine if an input integer is a semiprime
number. A semiprime number is a number that has 2 prime factors. If the number
is semiprime, it returns the boolean true. Otherwise, the function returns the
boolean false.
*/
bool is_semiprime(long n){
	
	for (int i = 2; i <= pow(n,0.5); i++){ //for loop initializing the divisor
	
		if (n%i == 0){ //if the remainder = 0
		
			if (is_prime(i) && is_prime(n/i)) //if both factors are prime
				return true;
		} //of if
	} //of for
	return false;
} //of is_semiprime

/*
The purpose of this function is to reverse an integer number that is input. It
keeps dividing the input number by 10 and adding the remainders until the input
number equals 0. It then returns the reversed number.
*/
long reverse_num(long n){
	
	long reverse = 0, remainder; //initialize reversed number and remainder
	
	while (n != 0){ //while the input isn't 0
		remainder = n%10; //find the remainder
		reverse = reverse*10 + remainder; //multiply prev. by 10 to shift right
		n = n/10; //get next number
	} //of while
	
	return reverse;
} //of reverse_num

/*
The purpose of this function is to determine if an input integer is a
palindrome. A palindrome is a number that is the same value forward and
backward. If the number is a palindrome, the boolean true is returned. If the 
number isn't, the function returns the boolean false.
*/
bool is_palindrome(long n){
	long reverse = reverse_num(n); //reverse the input number
	
	if (reverse == n) //if the number and it's reverse are equal
		return true;
	
	else //if they aren't equal
		return false;
} //of is_palindrome

/*
The purpose of this function is to determine if an input integer is emirp or
not. An emirp number is prime forward and reversed, but is not a palindrome.
If the number is emirp, then the boolean true is returned. If it is not,
the function returns the boolean false.
*/
bool is_emirp(long n){
	//call functions reverse_num, is_prime, and is_palindrome
	long reverse = reverse_num(n);
	bool prime1 = is_prime(n);
	bool prime2 = is_prime(reverse);
	bool pal = is_palindrome(n);
	
	if (prime1 && prime2){ //if forward and reverse are prime
		if (!pal){ //if it isn't a palindrome
			return true;
		} //of if
		else
			return false;
	} //of if
	else
		return false;
} //of is_emirp

/*
The purpose of this function is to determine if an input integer is emirpimes
or not. An emirpimes number has two prime factors forward and reversed, but is
not a palindrome. If the number is emirpimes, then the boolean true is returned.
If it is not, the function returns the boolean false.
*/
bool is_emirpimes(long n){
	//call functions reverse_num, is_semiprime, and is_palindrome
	long reverse = reverse_num(n);
	bool semi1 = is_semiprime(n);
	bool semi2 = is_semiprime(reverse);
	bool pal = is_palindrome(n);
	
	if (semi1 && semi2){ //if forward and reverse are both semiprime
		if (!pal){ //if it isn't a palindrome
			return true;
		} //of if
		else
			return false;
	} //of if
	else
		return false;
} //of is_emirpimes

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
      cout << num << ":" << reverse_num(num) << endl;
    break;
  } // of case 2

  case 3 : {
    long num;
    while (cin >> num)
     cout << num << ":" << is_palindrome(num) << endl;
    break;
  } // of case 3   

  case 4 : {
    long num;
    while (cin >> num)
     cout << num << ":" << is_emirp(num) << endl;
    break;
  } // of case 4

  case 5 : {
    long num;  
    while (cin >> num)
      cout << num << ":" << is_semiprime(num) << endl;
    break;
  } // of case 5

  case 6 : {
    long num;
    while (cin >> num)
      cout << num << ":" << is_emirpimes(num) << endl;
    break;
  } // of case 6    
    
  } // of switch
} // of main
