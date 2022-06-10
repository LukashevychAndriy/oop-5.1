#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	double first, second;
public:
	Point();
	Point(double, double);
	Point(const Point&);

	double Distance() const;

	void SetX(double);
	void SetY(double);
	double GetX() const { return this->first; };
	double GetY() const { return this->second; };

	// Operators

	operator string() const;
	friend ostream& operator << (ostream&, const Point&);
	friend istream& operator >> (istream&, Point&);

	Point& operator = (const Point&);

	Point operator ++();
	Point operator --();
	Point operator ++(int);
	Point operator --(int);
};
