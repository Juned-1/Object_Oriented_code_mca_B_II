#ifndef Shape_H
#define Shape_H
#include<iostream>
#include<cstring>
class Shape{
    private:
        char * name;
    public:
        Shape(){name = NULL;}
        Shape(char *);
        virtual double area() = 0; //pure virtual function thats make class as abstarct
        virtual double volume() = 0;
        virtual void print();
        virtual ~Shape(); //virtual destructor to allow run child class destructor first dynamically
};
Shape::Shape(char * sname):name(new char[strlen(sname)+1])
{
    strcpy(name,sname);
}
void Shape::print()
{
    std::cout<<name<<std::endl;
}
Shape::~Shape()
{
    delete [] name;
    std::cout<<"Destructor of Shape is called"<<std::endl;
}
#endif //Shape_H