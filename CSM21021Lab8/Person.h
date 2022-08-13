#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include<iostream>
#include<cstring>
using namespace  std;
class Person{
    private:
        char * name;
        long adhaar;
    public:
        Person(){name = NULL; adhaar = 0;}
        Person(char *,long);
        Person(const Person &);
        ~Person();
        Person & operator=(Person &);
        void print();
};
Person::Person(char * pname,long padhaar):name(new char[strlen(pname)+1]),adhaar(padhaar)
{
    strcpy(this->name,pname);
}
Person::Person(const Person & p):name(new char[strlen(p.name)+1]),adhaar(p.adhaar)
{
    strcpy(this->name,p.name);
}
Person::~Person()
{
    delete [] name;
    adhaar = 0;
}
Person & Person::operator=(Person & p)
{
    if(this!=&p){
        name = new char[strlen(p.name)+1];
        strcpy(this->name,p.name);
        adhaar = p.adhaar;
    }
    return *this;
}
void Person::print(){
    cout<<"Person details:-"<<endl;
    cout<<"Name = "<<name<<endl;
    cout<<"Adhaar Number = "<<adhaar<<endl;
}
#endif // PERSON_H_INCLUDED
