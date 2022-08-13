#ifndef METERCLASS_H_INCLUDED
#define METERCLASS_H_INCLUDED
#include<iostream>
using namespace std;
class Meter{
    private:
        double distanceInMeter;
    public:
        Meter();
        Meter(double distanceInft); //one argument constractor conversion
        operator double()const; //operator casting function
        double getMeter()const;
        friend istream & operator>>(istream &, Meter &);
        friend ostream & operator<<(ostream &, Meter &);
};
Meter::Meter()
{
    distanceInMeter = 0.0;
}
Meter::Meter(double distanceInft)
{
    //1 feet = 0.3048 meter
    distanceInMeter = distanceInft * 0.3048;
}
Meter::operator double()const{
    //1 meter = 3.28084 feet
    float distInft = distanceInMeter * 3.28084;
    return distInft;
}
double Meter::getMeter()const
{
    return distanceInMeter;
}
istream & operator>>(istream & in, Meter & m)
{
    cout<<"Enter distance in meter:";
    in>>m.distanceInMeter;
    return in;
}
ostream & operator<<(ostream & out, Meter & m)
{
    out<<"Distance in Meter : "<<m.distanceInMeter<<endl;
    return out;
}
#endif // METERCLASS_H_INCLUDED