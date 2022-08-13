#ifndef Cylinder_H
#define Cylinder_H
#include"Circle.h"
class Cylinder : public Circle{
    private:
        double height;
    public:
        Cylinder() {height = 0.0;}
        Cylinder(double, double, char *);
        double area();
        double volume();
        void print();
        virtual ~Cylinder();
};
Cylinder::Cylinder(double h, double r, char * n) : Circle(r,n){
    height = h;
}
double Cylinder::area(){
    double r = getRadius();
    double area = 2*pi*r*(r+height);
    return area;
}
double Cylinder::volume(){
    double r = getRadius();
    double vol = pi*r*r*height;
    return vol;
}
void Cylinder::print(){
    Shape::print();
    std::cout<<"Area of cylinder = "<<area()<<std::endl;
    std::cout<<"Volume of Cylinder = "<<volume()<<std::endl;
}
Cylinder::~Cylinder(){
    height = 0;
    std::cout<<"Destructor of Cylinder is called"<<std::endl;
}
#endif