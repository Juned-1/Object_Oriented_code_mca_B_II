#ifndef Circle_H
#define Circle_H
#define pi 3.141592
#include"Shape.h"
class Circle : public Shape{
    private:
        double radius;
    public:
        Circle(){radius = 0;}
        Circle(double, char *);
        virtual double area();
        virtual double volume();
        virtual void print();
        double getRadius()const;
        virtual ~Circle();
};
Circle::Circle(double r, char * n) : Shape(n)
{
    radius = r;
}
double Circle::area()
{
    double area = pi * radius * radius;
    return area;
}
double Circle::volume()
{
    std::cout<<"Volume of circle can not be calculated"<<std::endl;
    return 0;
}
void Circle::print()
{
    Shape::print();
    std::cout<<"Area of circle = "<<area()<<std::endl;
    volume();
}
double Circle::getRadius()const{
    return radius;
}
Circle::~Circle()
{
    radius = 0;
    std::cout<<"Destructor of Circle is called"<<std::endl;
}
#endif // Circle_H_INCLUDED