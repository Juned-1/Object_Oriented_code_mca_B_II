#ifndef FARENHEIT_H_INCLUDED
#define FAERENHEIT_H_INCLUDED
#include<iostream>
using namespace std;
class Celsius;
class Farenheit{
    private:
        double temperatureInfar;
    public:
        Farenheit(double = 0.0); //Parameterized constructor
        Farenheit(Celsius &); //Type Conversion using constructor -- celsius to farenheit
        operator Celsius(); //Type Conversion using operator function -- farenheit to celsius
        double getTemperature()const{return temperatureInfar;}
        friend istream & operator>>(istream &, Farenheit &);
        friend ostream & operator<<(ostream &, Farenheit &);
};
Farenheit::Farenheit(double temp)
{
    temperatureInfar = temp;
}
istream & operator>>(istream & in, Farenheit & thisObject)
{
    in>>thisObject.temperatureInfar;
    return in;
}
ostream & operator<<(ostream & out, Farenheit & thisObject)
{
    out<<"Farenheit temperature : "<<thisObject.temperatureInfar<<endl;
    return out;
}
class Celsius{
    private:
        double temperatureInCel;
    public:
        Celsius(double = 0.0);
        double getTemperature()const{return temperatureInCel;}
        friend istream & operator>>(istream &, Celsius &);
        friend ostream & operator<<(ostream &, Celsius &);
};
Celsius::Celsius(double temp)
{
    temperatureInCel = temp;
}
istream & operator>>(istream & in, Celsius & thisObject)
{
    in>>thisObject.temperatureInCel;
    return in;
}
ostream & operator<<(ostream & out, Celsius & thisObject)
{
    out<<"Celsius temperature : "<<thisObject.temperatureInCel<<endl;
    return out;
}
Farenheit::Farenheit(Celsius & c){
    temperatureInfar = c.getTemperature()*9/5+32;
}
Farenheit::operator Celsius()
{
    double temperature = (temperatureInfar-32)*5/9;
    Celsius c(temperature);
    return c;
}
#endif // FARENHEIT_H_INCLUDED
