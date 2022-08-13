#include<iostream>
#include<cstring>
using namespace std;
class Driver{
    private:
        char * name;
        int age;
    public:
        Driver(char * = (char *)"Junaid",int = 0);
        Driver(Driver&);
        friend ostream& operator <<(ostream&, Driver &);
        ~Driver();
};
Driver::Driver(char * name, int age):name(new char[strlen(name)+1]),age(age){
    strcpy(this->name,name);
    cout<<"Driver::Driver() --Parameterized constructor is called"<<endl;
}
Driver::Driver(Driver & d):name(new char[strlen(d.name)+1]),age(d.age){
    strcpy(this->name,d.name);
    cout<<"Driver::Driver() --Copy constructor is called"<<endl;
}
ostream& operator <<(ostream& out,Driver & d){
    out<<"Name = "<<d.name<<endl;
    out<<"Age = "<<d.age<<endl;
    return out;
}
Driver::~Driver(){
    delete [] name;
    cout<<"Driver::~Driver() destructor called"<<endl;
}
class Automobile{
    private:
        Driver & d;
        char * make;
        int year;
    public:
        Automobile(Driver &,char * = (char *)"Safari",int = 0);
        Automobile(Automobile&);
        friend ostream& operator <<(ostream&,Automobile&);
        ~Automobile();
};
Automobile::Automobile(Driver & d1,char * make,int year):d(d1),make(new char[strlen(make)+1]),year(year){
    strcpy(this->make,make);
    cout<<"Automobile::Automobile() --parameterized constructor is called"<<endl;
}
Automobile::Automobile(Automobile & a):d(a.d),make(new char[strlen(make)+1]),year(a.year){
    strcpy(make,a.make);
    cout<<"Automobile::Automobile() --Copy constructor is called"<<endl;
}
ostream& operator<<(ostream& out,Automobile & a){
    out<<a.d;
    out<<"Make = "<<a.make<<endl;
    out<<"Year = "<<a.year<<endl;
    return out;
}
Automobile::~Automobile()
{
    delete [] make;
    cout<<"Automobile::~Automobile destructor is called"<<endl;
}
int main(){
    char driverName[] ={"Mithun Borah"};
    int driverage = 25;
    char make[] = {"Hyaudai i20"};
    int manufactureYear = 2022;
    Driver d1(driverName, driverage);
    Automobile i20(d1, make, manufactureYear);
    cout<<d1;
    cout<<i20;
    {
        Automobile secondi20(i20);
        cout<<secondi20;
    }
    return 0;
}