
#include "Account.h"

/////////////////Account Class//////////////////

Account::Account(string n, int num, int c) :
	name(n), number(num), code(c), amount(0), spend(0) {}

void Account::cancelAccount(List* L, Account* &selected) {
	if (amount != 0) {
		expout ex;
		ex.reason = "\tThere is money in the account and can't be deleted";
		throw ex;
	}
	else {
		L->removeSelected(L->prevLink(code));
		selected = selected->startOperation(L);
	}
}

int len(int number) {
	int counter = 0;
	while (number) {
		number = number / 10;
		counter++;
	}
	return counter;
}

Account* Account::startOperation(List* L) {
	try {
		while (true)
		{
			int code, number;
			string answer;
			cout << "\n\tdo you want to access your account? (Y/N)\n"
				<< "\t[\"No\" will let you to create new account]: ";
			cin >> answer;
			while (answer != "y" && answer != "Y" && answer != "N" && answer != "n") {
				cout << "\ttry again: ";
				cin >> answer;
			}
			cout << "\tenter the account number: ";
			cin >> number;
			while (len(number) != 6) {
				cout << "\tnumber must be exact 6 digits, please try again: ";
				cin >> number;
			}
			cout << "\tenter the secret code: ";
			cin >> code;
			while (len(code) != 4) {
				cout << "\tnumber must be exact 4 digits, please try again: ";
				cin >> code;
			}
			if (answer == "Y" || answer == "y") {
				if (L->includes(number) && L->includes(number)->value->code == code) {
					return L->includes(number)->value;
				}
				else
					cout << "\tAccount not found OR wrong code" << endl;
			}
			else {
				string name;
				while (L->includes(number) || len(number) != 6) {
					cout << "\tAccount number already in use, please try another number\n"
						<< "\tenter diffrent account number: ";
					cin >> number;
				}
				cout << "\tplease provide your name: ";
				cin.get();
				getline(cin, name);
				Account* val = new Account(name, number, code);
				L->add(val);
				cout << "\tAccount created successfully\n\n";
				return val;
			}
		}
	}
	catch (...) {
		cout << "error";
	};
}

void Account::showCash() {
	cout << "\tyour amount is " << amount << " NIS" << endl;
}

void Account::subCash() {
	int money;
	cout << "\tHow much money do you like to draw? ";
	cin >> money;
	expout ex;
	if (amount < money) {
		ex.reason = "\tYou don't have enough money";
		throw ex;
	}
	if (money > 1000) {
		ex.reason = "\tYou can't draw more than 1000 NIS at once";
		throw ex;
	}
	int check = difftime((now / 60) % 60, time_draw.tm_min);
	if (check >= 1)
		spend = 0;
	if (spend + money > 1000) {
		now += 60;
		ex.reason = "\tYou try to spend more than 1000 NIS in one minute\n"
			"\tIn that case, you will able to spend until 1000 NIS at " + (string)(ctime(&now));
		throw ex;
	}
	time_draw.tm_min = (now / 60) % 60;
	spend += money;
	amount -= money;
	cout << "\tyou get " << money << " NIS successfully" << endl;
}

void Account::addCash() {
	int chak;
	cout << "\tenter the amount of the chak: ";
	cin >> chak;
	if (chak <= 10000) {
		amount += chak;
		cout << "\tyou add " << chak << " NIS to your account successfully" << endl;
	}
	else {
		expout ex;
		ex.reason = "\tyou can't add more than 10,000 NIS at once";
		throw ex;
	}
}

Account& Account::operator=(const Account& A) {
	name = A.name;
	number = A.number;
	code = A.code;
	amount = A.amount;
	time_draw = A.time_draw;
	spend = A.spend;
	return *this;
}

