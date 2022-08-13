#ifndef METERCLASS_H_INCLUDED
#define METERCLASS_H_INCLUDED
#include<iostream>
using namespace std;

class Meter{

    private:

        float  distanceInMeter;
    public:
        Meter();
        Meter( float distanceInCm);             // one argument conversion constructor
        operator float()const;                  // operator casting function
        float getMeter() const;
        friend istream & operator>>(istream &, Meter &);
        friend ostream & operator<<(ostream & , Meter &);

};
// implementation

Meter::Meter(){

    distanceInMeter=0.0;

}
Meter::Meter( float distanceInCm){

    distanceInMeter=distanceInCm/100;

}
Meter::operator float()const{

    float dInCm = distanceInMeter*100;
    return dInCm;

}
float Meter::getMeter() const{

    return distanceInMeter;
}
istream & operator>>(istream &in , Meter & thisObject){

    cout<<"Enter the distance in Meter : ";
    in>>thisObject.distanceInMeter;
    return in;

}
ostream & operator<<(ostream & out , Meter & thisObject){

    out<<"Distance in Meter : "<< thisObject.distanceInMeter<<endl;
    return out;
}

#endif // METERCLASS_H_INCLUDED
