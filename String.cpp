#include<iostream>
#include<cstring>
using namespace std;
class String{
    private:
        char * str;
        unsigned int size;
    public:
        String(const char * = 0);
        ~String();
        String(const String &);
        //assignment operator is overloaded only by member function
        //It is binary operattor, hence one argument will be implicit and another explicit
        String operator=(const String &); //string object to string object assignment
        String operator=(const char *); //charcter array or literal to string object assignment
        friend ostream & operator<<(ostream &,String);
        String operator+(const String &);
        String operator+(const char *);
        friend String operator+(const char *,const String &);
        friend String operator+(const char *,const char *);
};
String::String(const char * s)
{
    if(s == 0)
    {
        str = 0;
        size = 0;
    }
    else
    {
        str = new char[strlen(s)+1];
        strcpy(str,s);
        size = strlen(s);
    }
}
String::~String()
{
    delete [] str;
    size = 0;
}
String::String(const String & s):str(new char[strlen(s.str)+1]),size(strlen(s.str)+1)
{
    strcpy(str,s.str);
}
String String::operator=(const String & s)
{
    //condition checking for same object assignment x=x
    if(this!=&s)
    {
        this->str = new char[strlen(s.str)+1];
        strcpy(this->str,s.str);
        this->size = strlen(s.str);
    }
    return *this;
}
String String::operator=(const char * s)
{
    if(this->str!=NULL)
    {
        if(strcmp(this->str,s)!=0)
        {
            this->str = new char[strlen(s)+1];
            this->str = strcpy(this->str,s);
            size = strlen(s);
        }
    }
    else
    {
        this->str = new char[strlen(s)+1];
        this->str = strcpy(this->str,s);
        size = strlen(s);
    }
    return *this;
}
ostream & operator<<(ostream & out, String s)
{
    out<<s.str<<endl;
    return out;
}
String String::operator+(const String & s)
{
    String tmps;
    if(this->str==NULL && s.str==NULL)
    {
        tmps.str = 0;
        tmps.size = 0;
    }
    else if(this->str!=NULL && s.str==NULL)
    {
        tmps.str = new char[strlen(this->str)+1];
        strcpy(tmps.str,this->str);
        tmps.size = strlen(this->str);
    }
    else if(this->str==NULL && s.str!=NULL)
    {
        tmps.str = new char[strlen(s.str)+1];
        strcpy(tmps.str,s.str);
        tmps.size = s.size;
    }
    else
    {
        tmps.str = new char[strlen(this->str)+strlen(s.str)+1];
        strcpy(tmps.str,this->str);
        strcat(tmps.str,s.str);
        tmps.size = strlen(this->str)+strlen(s.str);
    }
    return tmps;
}
String String::operator+(const char * c)
{
    String tmps;
    if(this->str==NULL && c ==NULL)
    {
        tmps.str = 0;
        tmps.size = 0;
    }
    else if(this->str!=NULL && c==NULL)
    {
        tmps.str = new char[strlen(this->str)+1];
        strcpy(tmps.str,this->str);
        tmps.size = strlen(this->str);
    }
    else if(this->str==NULL && c!=NULL)
    {
        tmps.str = new char[strlen(c)+1];
        strcpy(tmps.str,c);
        tmps.size = strlen(c);
    }
    else
    {
        tmps.str = new char[strlen(this->str)+strlen(c)+1];
        strcpy(tmps.str,this->str);
        strcat(tmps.str,c);
        tmps.size = strlen(this->str)+strlen(c);
    }
    return tmps;
}
String operator+(const char * c, const String & s)
{
    String tmps;
    if(c==NULL && s.str==NULL)
    {
        tmps.str = 0;
        tmps.size = 0;
    }
    else if(c!=NULL && s.str==NULL)
    {
        tmps.str = new char[strlen(c)+1];
        strcpy(tmps.str,c);
        tmps.size = strlen(c);
    }
    else if(c==NULL && s.str!=NULL)
    {
        tmps.str = new char[strlen(s.str)+1];
        strcpy(tmps.str,s.str);
        tmps.size = s.size;
    }
    else
    {
        tmps.str = new char[strlen(c)+strlen(s.str)+1];
        strcpy(tmps.str,c);
        strcat(tmps.str,s.str);
        tmps.size = strlen(c)+strlen(s.str);
    }
    return tmps;
}
String operator+(const char * c1,const char * c2)
{
    String tmps;
    if(c1==NULL && c2==NULL)
    {
        tmps.str = 0;
        tmps.size = 0;
    }
    else if(c1!=NULL && c2==NULL)
    {
        tmps.str = new char[strlen(c1)+1];
        strcpy(tmps.str,c1);
        tmps.size = strlen(c1);
    }
    else if(c1==NULL && c2!=NULL)
    {
        tmps.str = new char[strlen(c2)+1];
        strcpy(tmps.str,c2);
        tmps.size = strlen(c2);
    }
    else
    {
        tmps.str = new char[strlen(c1)+strlen(c2)+1];
        strcpy(tmps.str,c1);
        strcat(tmps.str,c2);
        tmps.size = strlen(c1)+strlen(c2);
    }
    return tmps;
}
int main()
{
    String s1 = "C++ Book",s2,s3;
    cout<<s1;
    s3 = s2 = s1;
    cout<<s2;
    cout<<s3;
    s3 = "Computer Architecture";
    cout<<s3;
    s1 = "Hello";
    s2 = "World";
    s3 = s1+s2;
    cout<<s3;
    String s4, s5 = "Hello";
    cout<<s4+s5;
    cout<<s5 + "";
    cout<<s5 + "there";
    cout<<s4 + "";
    cout<<s4 +"there";
    cout<<""+s4;
    cout<<"Hello"+s4;
    cout<<""+s5;
    cout<<"Hello"+s5;
    cout<<""+"";
    cout<<"Hi"+"";
    cout<<""+"there";
    cout<<"Hi"+" there!";
    return 0;
}