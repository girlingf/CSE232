#include <iostream>
#include <iomanip>
/*
xir and fjg 31/1/2017
Integral approx.
*/
using std::cin;
using std::cout;
using std::endl;



double fn(double x)
{
	double out = (-6.0)*x*x + 5.0*x + 3.0;
	return out;
}
double integral(double x)
{
	double out = (-2.0)*x*x*x + 5.0/2.0*x*x + 3.0*x;
	return out;
}
double trapezoid(double a, double b, long n)
{
	double area = 0.0;
	double vole = (b-a)/n;											//vole represents the length of each trapezoid along the x axis
	for(long i = 0; i < n; i++)
	{
		area += (vole*(fn(a +(i*vole))+fn(a + ((i+1)*vole))))/2.0; 	//fn(a +(i*vole)) starts at a and increases by vole each time
	} 																//fn(a+((i+1)*vole)) starts at a+vole and increases by vole each time;
	return area;
}
int main(int argc, char const *argv[])
{
	float tol;
	long nguess;
	double dif; 
	cout << "Tolerance:";
	cin >> tol;
	cout << "Initial Trapezoid count:";
	cin >> nguess;
	cout << endl;
	
	dif = integral(1)-trapezoid(0,1,nguess);
	
	while(dif > tol)
	{
		cout << "Result:" << trapezoid(0,1,nguess) << ", " << "traps:" << nguess << ", " << "dif:" << dif << endl;
		nguess *= 2;
		dif = integral(1)-trapezoid(0,1,nguess);
	}
	cout << "Trap count:" << nguess << ", " << "estimate:" << trapezoid(0,1,nguess) << ", " << "exact:" << integral(1) << ", " << "tolerance:" << tol << endl;

		
}






