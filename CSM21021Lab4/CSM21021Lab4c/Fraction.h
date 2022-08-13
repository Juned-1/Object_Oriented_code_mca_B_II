
#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED
#include<iostream>
using namespace std;
class Fraction{

	private:
		long num;	// numerator of the fraction
		long den;	// denominator of the fraction
		// helper function
		long gcd( long, long);
		void reduce();
        void adjustSign();
	public:
		// all members and friend functions declarations will be here
		Fraction (long = 0,long = 1);
		Fraction(Fraction &);
		friend ostream & operator<<(ostream &, Fraction &);
        friend istream & operator>>(istream &, Fraction &);
		Fraction & operator++();
		friend Fraction operator+(Fraction &, Fraction&);
		friend Fraction operator-(Fraction &, Fraction&);
        friend Fraction operator*(Fraction &, Fraction&);
		friend Fraction operator/(Fraction &, Fraction&);
		friend bool operator<(Fraction &, Fraction &);
		friend bool operator<=(Fraction &, Fraction &);
		friend bool operator>(Fraction &, Fraction &);
		friend bool operator>=(Fraction &, Fraction &);
		friend bool operator==(Fraction &, Fraction &);
		friend bool operator!=(Fraction &, Fraction &);
};

inline long Fraction:: gcd( long x, long y){
    // recursive function
    return ( x==0)? y :  gcd(y%x,x);
}
void Fraction::reduce(){

    long factor = gcd(this->num,this->den);
    this->num = (this->num)/factor;
    this->den = ( this->den)/factor;

}
void Fraction::adjustSign()
{
    if(den<0)
    {
        num = -num;
        den = -den;
    }
}
inline Fraction::Fraction (long x,long y):num(x), den(y==0?1:y){
    //use only member initialization
}
inline Fraction::Fraction(Fraction & f):num(f.num), den(f.den){
    // uses only member initialization list
}
ostream & operator<<(ostream & out,Fraction & f)
{
    out<<"Fraction : ";
    f.adjustSign();
    out<< f.num <<"/"<<f.den<<endl;
    return out;
}
istream & operator>>(istream & in, Fraction & f)
{
    cout<<"Enter numerator:";
    in>>f.num;
    cout<<"Enter denominator:";
    in>>f.den;
    if(f.den==0)
        f.den = 1;
    f.reduce();
    return in;
}
Fraction & Fraction::operator++()
{
   ++num;
   ++den;
   return *(this);
}
Fraction operator+(Fraction & f1, Fraction & f2)
{
    long n = f1.num * f2.den + f2.num * f1.den;
    long d = f1.den * f2.den;
    Fraction f(n,d);
    f.reduce();
    return f;
}
Fraction operator-(Fraction & f1, Fraction & f2)
{
    long n = f1.num * f2.den - f2.num * f1.den;
    long d = f1.den * f2.den;
    Fraction f(n,d);
    f.reduce();
    return f;
}
Fraction operator*(Fraction & f1, Fraction & f2)
{
    long n = f1.num * f2.num;
    long d = f1.den * f2.den;
    Fraction f(n,d);
    f.reduce();
    return f;
}
Fraction operator/(Fraction & f1, Fraction& f2)
{
    long n = f1.num * f2.den;
    long d = f1.den * f2.num;
    Fraction f(n,d);
    f.reduce();
    return f;
}
bool operator<(Fraction & f1, Fraction & f2)
{
    f1.adjustSign();
    f2.adjustSign();
    long y = f1.num*f2.den-f1.den*f2.num;
    return (y<0);
}
bool operator<=(Fraction & f1, Fraction & f2)
{
    f1.adjustSign();
    f2.adjustSign();
    long y = f1.num*f2.den-f1.den*f2.num;
    return (y<=0);
}
bool operator>(Fraction & f1, Fraction & f2)
{
    f1.adjustSign();
    f2.adjustSign();
    long y = f1.num*f2.den-f1.den*f2.num;
    return (y>0);
}
bool operator>=(Fraction & f1, Fraction & f2)
{
    f1.adjustSign();
    f2.adjustSign();
    long y = f1.num*f2.den-f1.den*f2.num;
    return (y>=0);
}
bool operator==(Fraction & f1, Fraction & f2)
{
    f1.adjustSign();
    f2.adjustSign();
    long y = f1.num*f2.den-f1.den*f2.num;
    return (y==0);
}
bool operator!=(Fraction & f1, Fraction & f2)
{
    f1.adjustSign();
    f2.adjustSign();
    long y = f1.num*f2.den-f1.den*f2.num;
    return (y!=0);
}
void swap(Fraction & x,Fraction & y)
{
    Fraction temp = x;
    x = y;
    y = temp;
}
void sort(Fraction f[],int size)
{
    //selection sort
    int min_id;
    for(int i=0;i<size-1;i++)
    {
        min_id=i;
        for(int j=i+1;j<size;j++)
        {
            if(f[j]<f[min_id])
                min_id=j;
        }
        if(min_id!=i)
            swap(f[min_id],f[i]);
    }
}
#endif // FRACTION_H_INCLUDED