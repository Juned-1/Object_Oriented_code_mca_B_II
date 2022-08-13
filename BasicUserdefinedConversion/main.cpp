#include <iostream>
#include "MeterClass.h"

using namespace std;

int main()
{
    Meter m1;
    float cm1;
    cin>>m1;
    cm1=m1;         // conversion from user defined class Meter object to float
    cout<<"Distance equivalent to "<<m1.getMeter()<< " Meters : "<< cm1<< " Centimeters " <<endl;
    cout<<"Enter distance in centimeters : ";
    cin>>cm1;
    m1=cm1;         // conversion from primitive type float to user defined class Meter object
    cout<<m1;

    return 0;

}
