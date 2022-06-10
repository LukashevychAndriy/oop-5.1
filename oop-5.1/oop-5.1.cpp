#include "Point.h"
#include <iostream>
#include "Exception.h"
#include "NException.h"

using namespace std;

int main()
{
	Point a;
	Point b(3, 2);
	Point c(b);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	bool isDataCorrect;

	do {
		try {
			Point a;
			cin >> a;
			double x;
			cout << "Input x value: "; cin >> x;
			Point b(x, 13);
			isDataCorrect = true;
		}
		catch (Exception e)
		{
			cout << e.What() << endl;
			isDataCorrect = false;
		}
		catch (NException& e)
		{
			cout << e.getMessage() << endl;
			isDataCorrect = false;
		}
		catch (bad_exception* e)
		{
			cout << e->what() << endl;
			isDataCorrect = false;
		}
	} while (!isDataCorrect);

	cout << "Distance() = " << b.Distance() << endl;

	cout << a << endl;
	cout << a++ << endl;
	cout << a << endl;
	cout << ++a << endl;
	cout << a << endl;
	cout << --a << endl;
	cout << a << endl;
	cout << a-- << endl;
	cout << a << endl;
	
	return 0;
}
