#include "List.h"
#include "Account.h"
#include "Basic.h"
using namespace std;

///////////////// Main Section//////////////////

int main() {
	//installize list
	List L;
	Account* val1 = new Account("ariel", 123456, 1234);
	L.add(val1);
	Account* val2 = new Account("avihu", 023456, 5678);
	L.add(val2);
	Account* val3 = new Account("daniel", 103456, 9000);
	L.add(val3);
	Account* val4 = new Account("efrat", 120456, 1011);
	L.add(val4);
	Account* val5 = new Account("eitan", 123056, 1213);
	L.add(val5);
	Account* val6 = new Account("hodaya", 123406, 1478);
	L.add(val6);

	cout << "\n\n\t\t\t\t\t\tWellcome to Digital Bank\n";
	Account* selected = new Account("", 0, 0);
	selected = selected->startOperation(&L);
	int choice = -1;
	while (choice != 0) {
		cout << "\n\tpick an action:\n";
		cout << "\t0 - exit program\n";
		cout << "\t1 - draw money\n";
		cout << "\t2 - show amount\n";
		cout << "\t3 - chak money\n";
		cout << "\t4 - delete account\n";
		cout << "\n\tyour choice: ";
		cin >> choice;
		try {
			switch (choice)
			{
			case 1:
				now = time(0);
				selected->subCash();
				break;
			case 2:
				selected->showCash(); //check how much is left
				break;
			case 3:
				now = time(0);
				selected->addCash();
				break;
			case 4:
				selected->cancelAccount(&L, selected);
				break;
			}
		}
		catch (expout problem)
		{
			cout << problem;
		}
	}
	return 0;
}