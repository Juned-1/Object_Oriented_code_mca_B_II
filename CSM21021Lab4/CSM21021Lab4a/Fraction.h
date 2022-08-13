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
	public:
		// all members and friend functions declarations will be here
		Fraction();
		Fraction( long );
		Fraction (long,long);
		Fraction(Fraction &);
		void print();
		Fraction  inc();
		friend Fraction add(Fraction &, Fraction&);
		friend Fraction sub(Fraction &, Fraction&);
        friend Fraction mult(Fraction &, Fraction&);
		friend Fraction div(Fraction &, Fraction&);
};
// implementation of the member functions and friend function must be here.

inline long Fraction:: gcd( long x, long y){
    // recursive function
    return ( x==0)? y :  gcd(y%x,x);
}
void Fraction::reduce(){

    long factor = gcd(this->num,this->den);
    this->num = (this->num)/factor;
    this->den = ( this->den)/factor;

}

Fraction::Fraction():num(0),den(1){
    // uses only member initialization list
}
Fraction::Fraction( long x ): num(x), den(1){
    // uses only member initialization list
}
Fraction::Fraction (long x,long y):num(x), den(y){

    if (y == 0)
        den =1;

}

inline Fraction::Fraction(Fraction & f):num(f.num), den(f.den){
    // uses only member initialization list
}

void Fraction::print(){

    cout<<"Fraction : ";
    if (den < 0)
        cout<< -num <<"/"<< -den<<endl;
    else
        cout<< num <<"/"<<den<<endl;

}
Fraction Fraction::inc(){

    Fraction f;
    Fraction f1(1);
    f = add(*this, f1);
    return f;

}
Fraction  add(Fraction & f1, Fraction& f2){

    long n = f1.num * f2.den + f2.num * f1.den;
    long d = f1.den * f2.den;
    Fraction f(n,d);
    f.reduce();
    return f;

}
Fraction  sub(Fraction & f1, Fraction& f2){

    long n = f1.num * f2.den - f2.num * f1.den;
    long d = f1.den * f2.den;
    Fraction f(n,d);
    f.reduce();
    return f;
}
Fraction  mult(Fraction & f1, Fraction& f2){
    long n = f1.num * f2.num;
    long d = f1.den * f2.den;
    Fraction f(n,d);
    f.reduce();

    return f;

}
Fraction  div(Fraction & f1, Fraction& f2){
    long n = f1.num * f2.den;
    long d = f1.den * f2.num;
    Fraction f(n,d);
    f.reduce();
    return f;
}
#endif // FRACTION_H_INCLUDED