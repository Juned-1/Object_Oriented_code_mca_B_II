#include<iostream>
#include "Array.h"
#include<cstring>
using namespace std;
int main()
{
    Array a1;
    a1.fill(1,10,'a');
    cout<<a1<<endl;
    char msg[] = "Hello World";
    Array a2(msg,strlen(msg));
    cout<<a2<<endl;
    Array a3 = a2; //copy constructor is called
    cout<<a3<<endl;
    a1 = a3; //overloaded = is called
    cout<<a1<<endl;
    char msg2[] = "This is test work";
    Array a4(msg2,strlen(msg2));
    cout<<a4<<endl;
    if(a1 == a2)
        cout<<"a1 == a2"<<endl;
    else
        cout<<"a1 != a2"<<endl;
    if(a1 != a4)
        cout<<"a1! = a4"<<endl;
    else
        cout<<"a1 == a4"<<endl;
    cout<<a1[4];
    cout<<endl;
    //cout<<a1[12];
    a1[5] = 'D';
    cout<<a1<<endl;
    cout<<a1.min()<<endl;
    cout<<a1.max()<<endl;
    cout<<"Alphabet d is found at "<<a2.find('d')+1<<endl;
    cout<<"Alphabet o found at "<<a2.find(1,4,'o')+1<<endl;
    cout<<(int)a2.accumulate(3,4)<<endl;
    a2.copy(0,4,5);
    cout<<a2<<endl;
    cout<<"Number of occurance of l in a2 = "<<a2.count(1,9,'l')<<endl;
    a2.fill(6,10,'a');
    cout<<a2<<endl;
    return 0;
}