#include<iostream>
#define pi 3.141592
using namespace std;
double volume(float r){
    float vol = ((double)4/3)*pi*r*r*r;
    return vol;
}
int main()
{
    cout<<volume(4.5)<<endl;
    cout<<4/3<<endl;
}