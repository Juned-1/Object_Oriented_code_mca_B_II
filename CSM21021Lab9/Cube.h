#ifndef Cube_H
#define Cube_H
#include"Square.h"
class Cube : public Square{
    public:
        Cube(){}
        Cube(double,char *);
        double area();
        double volume();
        void print();
        virtual ~Cube();
};
Cube::Cube(double s, char * n) : Square(s,n){}
double Cube::area(){
    double s = getSide();
    double area = 6*s*s;
    return area;
}
double Cube::volume(){
    double s = getSide();
    double vol = s*s*s;
    return vol;
}
void Cube::print(){
    Shape::print();
    std::cout<<"Area of Cube = "<<area()<<std::endl;
    std::cout<<"Volume of Cube = "<<volume()<<std::endl;
}
Cube::~Cube(){
    std::cout<<"Desructor of Cube is called"<<std::endl;
}
#endif