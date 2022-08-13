#ifndef Square_H
#define Square_H
#include"Shape.h"
class Square : public Shape{
    private:
        double side;
    public:
        Square() {side = 0.0;}
        Square(double, char *);
        virtual double area();
        virtual double volume();
        virtual void print();
        double getSide() const;
        virtual ~Square();
};
Square::Square(double s, char * n) : Shape(n){
    side = s;
}
double Square::area(){
    double area = side * side;
    return area;
}
double Square::volume(){
    std::cout<<"Volume of Square can not be calculated"<<std::endl;
    return 0;
}
void Square::print(){
    Shape::print();
    std::cout<<"Area of Square = "<<area()<<std::endl;
    volume();
}
double Square::getSide()const{
    return side;
}
Square::~Square(){
    side = 0;
    std::cout<<"Destructor of Square is called"<<std::endl;
}
#endif