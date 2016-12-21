#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int rows = 30;
	double theta;

	cout << " Enter a value of theta so that, 15 <= theta <= 75 " << endl;
	cin >> theta;
	double radians = theta*(.0174532925);
	for (double i=1; i<=rows; i++)
	{
	double shelly =((double)i)*tan(radians);
	if (shelly >= 20 && shelly <= 30)
		shelly = 20;
		for (int j=1; j<=shelly; j++)
		{
			cout << "*";
		}
		cout <<"\n";
	}
return 0;
}
