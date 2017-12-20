#include <iostream>
#include <iomanip>

/*
CSE232 Section 001
1/18/17
Project 01
*/

using std::cin;
using std::cout;
using std::endl;

/*
This function finds the lbs of green gas emitted in one year by a car in three
scenarios: 
1) Using the given MPG 
2) Using the given MPG + 1
3) Using the given MPG + 5
All three values are then printed on one line separated by a single space.
*/

int main(int argc, char const *argv[])
{
	double mpg, miles_driven; //miles per gallon and miles driven per year
	double avg_emission = 19.6; //lbs CO2 / gallon of gas
	double total_ratio = 100.0/98.65;
	
	cout << std::fixed;
	
	//The two inputs taken from text files
	cin >> mpg >> miles_driven;
	
	//Scenario 1
	double yearly_emissions = (miles_driven / mpg) * avg_emission * total_ratio;
	
	//Scenario 2
	double yearly_emissions_1 = yearly_emissions - ((miles_driven / (mpg + 1.0))
	* avg_emission * total_ratio);
	
	//Scenario 3
	double yearly_emissions_2 = yearly_emissions - ((miles_driven / (mpg + 5.0))
	* avg_emission * total_ratio);
	
	//Print the three scenarios on a single line separated by a single space
	//rounded to two decimal places
	cout << std::setprecision(2) << yearly_emissions << " " <<
	yearly_emissions_1 << " " << yearly_emissions_2 << endl;
	
}
