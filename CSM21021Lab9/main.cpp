#include<cstring>
#include<iostream>
#include"Shape.h"
#include"Circle.h"
#include"Square.h"
#include"Cube.h"
#include"Cylinder.h"
#include"Sphere.h"
using namespace std;
//a polymorphic function -- overloaded or static polymorphism
void printShape(Shape * thisShape){
    thisShape->print();
    cout<<endl;
}
int main()
{
    Shape * shapePointerArray[] = {
        new Circle(2.3,(char *)"Circle"),
        new Square(3.4,(char *)"Square"),
        new Cylinder(3.4,5.6,(char *)"Cylinder"),
        new Cube(3.4,(char *)"Cube"),
        new Sphere(4.5,(char *)"Sphere")
    };
    for(unsigned int i = 0; i < 5; i++)
        printShape(shapePointerArray[i]);
    return 0;
}