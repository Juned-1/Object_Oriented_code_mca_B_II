#ifndef HGOURLYEMPLOYEE_H_INCLUDED
#define HOURLYEMPLOYEE_H_INCLUDED
#include"Person.h"
#include<cstring>
class HourlyEmployee:public Person{
    private:
        float ratePerHr;
        float hrsWorked;
        float calcSalary();
    public:
        HourlyEmployee(){ratePerHr = 0; hrsWorked = 0;}
        HourlyEmployee(char *, long, float, float);
        HourlyEmployee(HourlyEmployee &);
        ~HourlyEmployee();
        HourlyEmployee & operator=(HourlyEmployee &);
        void print();
};
float HourlyEmployee::calcSalary(){
    float sal = hrsWorked*ratePerHr;
    return sal;
}
HourlyEmployee::HourlyEmployee(char * hname,long hadhaar,float hratePerHr, float hhrsWorked):Person(hname,hadhaar){
    this->ratePerHr = hratePerHr;
    this->hrsWorked = hhrsWorked;
}
HourlyEmployee::HourlyEmployee(HourlyEmployee & hemp):Person(hemp){
    this->ratePerHr = hemp.ratePerHr;
    this->hrsWorked = hemp.hrsWorked;
}
HourlyEmployee::~HourlyEmployee()
{
    ratePerHr = 0;
    hrsWorked = 0;
}
HourlyEmployee & HourlyEmployee::operator=(HourlyEmployee & hemp)
{
    if(this!=&hemp){
        Person::operator=(hemp);
        ratePerHr = hemp.ratePerHr;
        hrsWorked = hemp.hrsWorked;
    }
    return *this;
}
void HourlyEmployee::print()
{
    cout<<"Hourly Employee details:-"<<endl;
    Person::print();
    cout<<"Salary = "<<calcSalary()<<endl;
}
#endif //HOURLYEMPLOYEE_H_INCLUDED
