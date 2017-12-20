
#include <iostream>
#include <iomanip>
/*
xir and fjg 17/1/2017
new horizon program
*/
using std::cin;
using std::cout;
using std::endl;


int main(int argc, char const *argv[])
{
	int days = 0;
	double disKm = 5584493340.0;
	double newKm;
	double disMi = 3470040014.0;
	double newMi;
	double tripTime;
	cout << std::fixed;
	
	cout << "Enter days since December 30 2016." << endl;
	cin >> days;
	newKm = disKm + static_cast<double>(days)*14.33*24.0*3600.0;
	newMi = disMi + static_cast<double>(days)*8.9*24.0*3600.0;
	cout << std::setprecision(2) << "Distance in Kilometers is " << newKm << endl;
	cout << std::setprecision(2) << "Distance in Miles is " << newMi << endl;
	tripTime = ((newKm / (299792.458))/3600.0)*2.0;
	cout << std::setprecision(2) << "Round trip radio communication would take " << tripTime <<" hours." << endl;
	
}
