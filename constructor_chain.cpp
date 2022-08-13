#include<iostream>
#include<cstring>
using namespace std;
class stud{
    private:
        char * name;
    public:
        stud(char * name):name(new char[strlen(name)+1]){
            strcpy(this->name,name);
        }
        stud(const stud & s):name(new char[strlen(name)+1]){
            strcpy(this->name,s.name);
        }
        void print(){cout<<"Name = "<<name<<endl;}
};
class student: public stud{
    private:
        int roll;
    public:
        student(char * name,int r):stud(name){
            roll = r;
        }
        student(const student & s):stud(s){
            this->roll = s.roll;
        }
        void print(){
            stud::print();
            cout<<"Roll number = "<<roll<<endl;
        }
};
int main()
{
    student s1((char *)"Junaid",21);
    s1.print();
    student s2(s1);
    s2.print();
    return 0;
}