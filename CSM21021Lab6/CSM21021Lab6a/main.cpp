#include<iostream>
#include"ClassMeter.h"
using namespace std;
int main()
{
    Meter m1;
    double ft;
    cin>>m1;
    ft = m1; //Conversion from user defined class Meter object to float
    cout<<"Distance equivalent to "<<m1.getMeter()<<" Meters : "<<ft<<" Feet"<<endl;
    cout<<"Enter distance in Feet:";
    cin>>ft;
    m1 = ft; //conversion from primitve type float to user defined class Meter object
    cout<<m1;
    return 0;
}