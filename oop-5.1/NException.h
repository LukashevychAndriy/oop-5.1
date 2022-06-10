#pragma once
#include <iostream>
#include <string>

using namespace std;

class NException
{
	string message;
public:
	NException(string message) : message(message) {}
	string getMessage() { return message; }
};
