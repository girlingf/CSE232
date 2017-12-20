#include <iostream>
#include <iomanip>

/*
xir and fjg 24/1/2017
Lab 2
*/

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	int input_number = 0;
	
	while (cin >> input_number){
	
		if (input_number < 0){
			cout << "Program Ended." << endl;
			break;
		}
		
		else if (input_number >= 0 && input_number <= 9){
			cout << "0 ";
			cout << input_number << endl;
		}
		
		else{
			int count = 0;
			while(input_number > 9){
				int placehold = 0;
				
				while(input_number > 0){
					placehold += input_number%10;
					input_number = input_number/10;
				}
				input_number = placehold;
				++count;
			}
			cout << count << " " << input_number << endl;
			input_number = 0;
		}
	}
	
		
}
