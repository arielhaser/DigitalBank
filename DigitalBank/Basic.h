#pragma once
#ifndef basic
#define basic

#include <iostream>
using namespace std;

extern time_t now;

struct expout
{
	string reason;
	friend ostream& operator<<(ostream& a, expout& ex);
};

#endif