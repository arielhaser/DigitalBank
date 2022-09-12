#pragma once
#ifndef list
#define list

#include <iostream>
#include <string>
#include <ctime>
#include "Basic.h"
#include "Account.h"
using namespace std;

struct expout;
class Account;

class List {
private:
	class Link {
	public:
		// data areas
		Account* value;
		Link* next;
		// constructor
		Link(Account* linkValue, Link* nextPtr);
		Link(const Link&);
		~Link();
	};
	// data field
	Link* last;

public:
	// constructors
	List();
	List(const List& l);
	~List();

	// operations
	void add(Account* value);
	Account* lastElement() const;
	Link* prevLink(int code) const;
	Link* includes(const int c) const;
	bool isEmpty() const;
	void removeLast();
	void clear();
	void removeSelected(Link* p);
};

#endif;