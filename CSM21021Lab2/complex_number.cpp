#include<iostream>
using namespace std;
class Complex{
    private:
        float real,imag;
    public:
        Complex(float = 0.0,float = 0.0);
        Complex(Complex &);
        inline float get_real() const;
        inline float get_imag() const;
        void print();
        void increment();
        void accumulate(Complex);
        Complex multiply(Complex);
        Complex add(Complex);
};
Complex::Complex(float real, float imag){
    this->real = real;
    this->imag = imag;
}
Complex::Complex(Complex & c){
    real = c.get_real();
    imag = c.get_imag();
}
inline float Complex::get_real() const{
    return real;
}
inline float Complex::get_imag() const{
    return imag;
}
void Complex::print(){
    cout<<real;
    if(imag>=0)
        cout<<"+"<<imag<<"*i"<<endl;
    else
        cout<<"-"<<-imag<<"*i"<<endl;
}
void Complex::increment(){
    real++;
}
void Complex::accumulate(Complex c){
    real+=c.get_real();
    imag+=c.get_imag();
}
Complex Complex::multiply(Complex c){
    float x,y;
    x = real*c.get_real()-imag*c.get_imag();
    y = real*c.get_imag()+c.get_real()*imag;
    Complex tmp(x,y);
    return tmp;
}
Complex Complex::add(Complex c){
    float x,y;
    x = real+c.get_real();
    y = imag+c.get_imag();
    Complex tmp(x,y);
    return tmp;
}
int main()
{
    Complex c1,c2(1.1),c3(2.2,3.3),c5,c6;
    c1 = c2.add(c3);
    c1.increment();
    Complex c4(c1);
    c5 = c4.add(c1);
    c5.accumulate(c1);
    c6 = c4.multiply(c5);
    c1.print();
    c2.print();
    c3.print();
    c4.print();
    c5.print();
    c6.print();
    return 0;
}