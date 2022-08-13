#include<iostream>
#include "Fraction.h"
using namespace std;
int main()
{
    Fraction fraction_array[5];
    for(int i = 0; i<5; i++)
        cin>>fraction_array[i];
    cout<<"Before Sorting:"<<endl;
    for(int i = 0; i<5; i++)
        cout<<fraction_array[i];
    sort(fraction_array,5);
    cout<<"After Sorting:"<<endl;
    for(int i = 0; i<5; i++)
        cout<<fraction_array[i];
    return 0;
}