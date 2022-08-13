#ifndef Sphere_H
#define Sphere_H
#include"Circle.h"
class Sphere : public Circle{
    public:
        Sphere(){}
        Sphere(double,char *);
        double area();
        double volume();
        void print();
        virtual ~Sphere();
};
Sphere::Sphere(double r, char * n) : Circle(r,n){}
double Sphere::area(){
    double r = getRadius();
    double area = 4*pi*r*r;
    return area;
}
double Sphere::volume(){
    double r = getRadius();
    double vol = (double)4/3*pi*r*r*r;
    return vol;
}
void Sphere::print(){
    Shape::print();
    std::cout<<"Area of Sphere = "<<area()<<std::endl;
    std::cout<<"Volume of Sphere = "<<volume()<<std::endl;
}
Sphere::~Sphere()
{
    std::cout<<"Destructor of Shape is called"<<std::endl;
}
#endif