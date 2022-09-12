#include "Basic.h"

time_t now = time(0);

ostream& operator<<(ostream& a, expout& ex) {
 a << ex.reason << endl;
 return a;
	}