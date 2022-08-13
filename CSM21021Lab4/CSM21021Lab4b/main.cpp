#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
    // main function to test your Fraction class

	Fraction f1, f2(2L,0L);
	Fraction f3(f1),f(-5,4);
	f1.print();
	f2.print();
	f3.print();
	f3 = add(f3,f);
	f3.print();
	f1=add(f2,f3);
	f1.print();
	f1=sub(f2,f3);
	f1.print();
	f1=mult(f2,f3);
	f1.print();
	f1.inc().inc().print();
	f1.print();
	f1=div(f2,f3);
	f1.print();
	return 0;
}
