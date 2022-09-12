#pragma once
#ifndef account
#define account

#include <iostream>
#include <string>
#include <ctime>
#include "List.h"
#include "Basic.h"
using namespace std;

class List;
struct expout;

class Account {
public:

	string name;
	int amount;
	tm time_draw{ 0 }; //the draw minute
	int spend; //credit

	int code;
	int number;
	//constractor
	Account(string n, int num, int c);
	void cancelAccount(List* L, Account* &selected);
	Account* startOperation(List* L);
	void subCash();
	void showCash();
	void addCash();
	Account& operator=(const Account& A);
};

#endif