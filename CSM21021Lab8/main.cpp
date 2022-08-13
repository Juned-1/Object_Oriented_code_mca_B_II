#include<iostream>
#include"Person.h"
#include"HourlyEmployee.h"
#include"SalaryEmployee.h"
using namespace std;
int main()
{
    Person p1((char *)"S.I.Singh",123456734);
    HourlyEmployee e2,e1((char *)"Vijay Kumar Shrotria",123459045,23,450.0);
    SalaryEmployee e3,e4((char *)"James Cook",2678976555,230000.40,32.0,27.0,120000.0);
    e2 = e1;
    e3 = e4;
    p1.print();
    e1.print();
    e2.print();
    e3.print();
    e4.print();
    Person p2(e1);
    HourlyEmployee e5(e2);
    SalaryEmployee e6(e4);
    p2.print();
    e5.print();
    e6.print();
    return 0;
}