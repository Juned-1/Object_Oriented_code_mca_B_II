#include <iostream>
#include<cstdlib>
using namespace std;
class Fraction
{
	private:
		long num;
		long den;
	    long gcd(long a,long b);
	public:
		Fraction();
		Fraction(long);
		Fraction(long,long);
		Fraction(Fraction & a);
		friend ostream& operator<<(ostream&,Fraction&);
		friend istream & operator>>( istream & in, Fraction & f);
		Fraction operator++();
		friend Fraction operator+(Fraction&,Fraction&);
		friend Fraction operator-(Fraction&,Fraction&);
		friend Fraction operator*(Fraction&,Fraction&);
		friend Fraction operator/(Fraction&,Fraction&);
		friend bool operator<(Fraction&,Fraction&);
		friend bool operator<=(Fraction&,Fraction&);
		friend bool operator>(Fraction&,Fraction&);
		friend bool operator>=(Fraction&,Fraction&);
		friend bool operator==(Fraction&,Fraction&);
		friend bool operator!=(Fraction&,Fraction&);
		};
		void sort( Fraction [] , int size);
	   ostream& operator<<(ostream& out,Fraction& a)
	   {
	   	Fraction s;
	   	int r;
	   	if(a.den<0)
	   	{
	   		a.den=-a.den;
	   		a.num=-a.num;
		   }
		{
			
		}
		   if(a.num==0)
		   {
		   	out<<a.num<<"/"<<a.den<<"\n";
	   }
	   else 
	   {
	   r=s.gcd(abs(a.num),a.den);
	   out<<a.num/r<<"/"<<a.den/r<<"\n";
}
    return out;
}
istream& operator>>(istream & in, Fraction & f)
{
      cout<<"Enter the numerator\n";
      in>>(f.num);
      cout<<"Enter the denominator\n";
      in>>(f.den);
      return in;
}
		Fraction::Fraction()
		{
			num=0;
			den=1;
		}
		long Fraction::gcd(long a,long b)
		{
			int gc;
			for(int i=1; i <= a && i <= b; ++i)
    {
        if(a%i==0 && b%i==0)
            gc= i;
    }
    return gc;

		
		}
		Fraction::Fraction(long a)
		{
			num=a;
			if(den==0)
			den=1;
		}
		Fraction::Fraction(long a ,long b)
		{
			num=a;
			den=b;
			if(den==0)
			den=1;
		}
		Fraction::Fraction(Fraction &a)
		{
			num=a.num;
			den=a.den;
		}
	  Fraction operator+(Fraction& a,Fraction& b)
	  {
	  	Fraction c,s;
	  	c.den=(a.den/s.gcd(a.den,b.den))*b.den;
	  	c.num=(c.den/a.den)*a.num+(c.den/b.den)*b.num;
	  	return c;
	   
	  }
	  Fraction operator-(Fraction& a,Fraction& b)
	  {
	  	Fraction c,s;
	  	c.den=(a.den/s.gcd(a.den,b.den))*b.den;
	  	c.num=(c.den/a.den)*a.num-(c.den/b.den)*b.num;
	  	return c;
	   }
	   Fraction operator*(Fraction& a,Fraction& b)
	  {
	  	Fraction c,s;
	  	c.den=a.den*b.den;
	  	c.num=a.num*b.num;
	  	return c;
	   
	  }
	  Fraction operator/(Fraction& a,Fraction& b)
	  {
	  	Fraction c,s;
  	   c.den=a.den*b.num;
	  	c.num=a.num*b.den;
	  	return c;
	   }
	   bool operator<(Fraction& a,Fraction& b)
	   {
	   	Fraction c,s;
	   	c.den=(a.den/s.gcd(abs(a.den),abs(b.den)))*b.den;
	  	if(((c.den/a.den)*a.num)<(c.den/b.den)*b.num)
	  	return true;
	  	else 
	  	return false;
	   }
	   	bool operator<=(Fraction& a,Fraction& b)
	   	{
	   	Fraction c,s;
	   	c.den=(a.den/s.gcd(abs(a.den),abs(b.den)))*b.den;
	  	if(((c.den/a.den)*a.num)<=(c.den/b.den)*b.num)
	  	return true;
	  	else 
	  	return false;	
		}
		bool operator>(Fraction& a,Fraction& b)
		{
			  	Fraction c,s;
	   	c.den=(a.den/s.gcd(abs(a.den),abs(b.den)))*b.den;
	  	if(((c.den/a.den)*a.num)>(c.den/b.den)*b.num)
	  	return true;
	  	else 
	  	return false;
		}
		bool operator>=(Fraction& a,Fraction& b)
		{
				  	Fraction c,s;
	   	c.den=(a.den/s.gcd(abs(a.den),abs(b.den)))*b.den;
	  	if(((c.den/a.den)*a.num)>=(c.den/b.den)*b.num)
	  	return true;
	  	else 
	  	return false;
		}
		bool operator==(Fraction& a,Fraction& b)
		{
				  	Fraction c,s;
	   	c.den=(a.den/s.gcd(abs(a.den),abs(b.den)))*b.den;
	  	if(((c.den/a.den)*a.num)==(c.den/b.den)*b.num)
	  	return true;
	  	else 
	  	return false;	
		}
		bool operator!=(Fraction& a,Fraction& b)
		{
					  	Fraction c,s;
	   	c.den=(a.den/s.gcd(abs(a.den),abs(b.den)))*b.den;
	  	if(((c.den/a.den)*a.num)!=(c.den/b.den)*b.num)
	  	return true;
	  	else 
	  	return false;
		}
		Fraction Fraction::operator++()
	  {
	  	Fraction b(1),c;
	  	Fraction a(num,den);
	  	c=a+b;
	  	return c;
	  }
void sort(Fraction a[], int n) {
   int i, j, min; 
   Fraction temp;
   for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
   }
}
int main(){
    Fraction fraction_array [5];
    for ( int i=0; i< 5; i++)
        cin>>fraction_array[i];
    cout<<"Before Sorting : " << endl;
    for (int i=0; i< 5; i++)
        cout<<fraction_array[i];
    sort(fraction_array, 5);
    cout<<"After Sorting : "<< endl;
    for ( int i=0; i< 5; i++)
        cout<<fraction_array[i];
    return 0;
}