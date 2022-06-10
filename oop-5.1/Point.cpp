#include "Point.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include "Exception.h"
#include "NException.h"

using namespace std;

Point::Point()
{
	first = 0;
	second = 0;
}

Point::Point(double x = 0, double y = 0)
{
	if (fabs(x) <= 100 && fabs(y) <= 100)
	{
		first = x;
		second = y;
	}
	else
	{
		throw new bad_exception();
	}
}

Point::Point(const Point& r)
{
	first = r.first;
	second = r.second;
}

void Point::SetX(double x) {
	this->first = x;
}

void Point::SetY(double y) {
	this->second = y;
}

double Point::Distance() const
{
	return sqrt(first * first + second * second);
}

// Operators

Point::operator string () const
{
	stringstream ss;

	ss << " x = " << first << endl;
	ss << " y = " << second << endl;

	return ss.str();
}

ostream& operator << (ostream& out, const Point& f)
{
	out << string(f);
	return out;
}

istream& operator >> (istream& in, Point& f)
{
	double x, y;

	cout << "Input coordinates:" << endl;
	cout << " x = "; in >> x;
	cout << " y = "; in >> y;
	
	if (abs(x) > 100) {
		throw NException("X is too big");
	}
	if (abs(y) > 100) {
		throw Exception("Y is too big");
	}

	f.first = x;
	f.second = y;
	return in;
}

Point& Point::operator = (const Point& r)
{
	first = r.first;
	first = r.first;
	return *this;
}

Point Point::operator ++()
{
	first++;
	return *this;
}

Point Point::operator --()
{
	first--;
	return *this;
}

Point Point::operator ++(int)
{
	Point t(*this);
	second++;
	return t;
}

Point Point::operator --(int)
{
	Point t(*this);
	second--;
	return t;
}
