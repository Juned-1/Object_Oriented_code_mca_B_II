#ifndef SALARYEMPLOYEE_H_INCLUDED
#define SALARYEMPLOYEE_H_INCLUDED
#include"Person.h"
class SalaryEmployee : public Person{
    private:
        float basicPay,hraPc,daPc,deductions;
        float calcSalary();
    public:
        SalaryEmployee(){basicPay = 0; hraPc = 0; daPc = 0; deductions = 0;}
        SalaryEmployee(char *, long, float, float, float, float);
        SalaryEmployee(SalaryEmployee &);
        ~SalaryEmployee();
        SalaryEmployee & operator=(SalaryEmployee &);
        void print();
};
float SalaryEmployee::calcSalary()
{
    float sal = basicPay+basicPay*daPc+basicPay*hraPc-deductions;
    return sal;
}
SalaryEmployee::SalaryEmployee(char * sname,long sadhaar,float sbasicPay,float shraPc,float sdaPc,float sdeductions):Person(sname,sadhaar)
{
    this->basicPay = sbasicPay;
    this->hraPc = shraPc;
    this->daPc = sdaPc;
    this->deductions = sdeductions;
}
SalaryEmployee::SalaryEmployee(SalaryEmployee & s):Person(s)
{
    this->basicPay = s.basicPay;
    this->hraPc = s.hraPc;
    this->daPc = s.daPc;
    this->deductions = s.deductions;
}
SalaryEmployee::~SalaryEmployee()
{
    basicPay = 0;
    hraPc = 0;
    daPc = 0;
    deductions = 0;
}
SalaryEmployee & SalaryEmployee::operator=(SalaryEmployee & s)
{
    if(this!=&s){
        Person::operator=(s);
        basicPay = s.basicPay;
        hraPc = s.hraPc;
        daPc = s.daPc;
        deductions = s.deductions;
    }
    return *this;
}
void SalaryEmployee::print()
{
    cout<<"Salary Employee details:-"<<endl;
    Person::print();
    cout<<"Salary = "<<calcSalary()<<endl;
}
#endif //SALARYEMPLOYEE_H_INCLUDED
