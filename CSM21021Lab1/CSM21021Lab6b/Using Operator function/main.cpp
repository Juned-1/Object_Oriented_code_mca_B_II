#include<iostream>
#include"Farenheit.h"
using namespace std;
int main()
{
    Farenheit f;
    Celsius c;
    cout<<"Enter temperature  in degree Farenheit:";
    cin>>f; //conversion from farenheit to celsius
    c = f;
    cout<<f<<c;
    cout<<"Enter temperature  in degree Celsius:";
    cin>>c;
    f = c; //conversion from celisus to farenheit
    cout<<f<<c;
    return 0;
}