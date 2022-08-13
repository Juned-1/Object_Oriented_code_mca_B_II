#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef char ElementType; //generic type declaration
class Array{
    private:
        ElementType * data;
        long size;
        void doublesize();
    public:
        static int DefaultArraySize;
        Array(int = DefaultArraySize);
        Array(ElementType *, long);
        Array(const Array &);
        ~Array();
        Array & operator=(const Array &);
        bool operator==(const Array &);
        bool operator!=(const Array &);
        ElementType & operator[](int);
        long getSize()const;
        ElementType min()const;
        ElementType max()const;
        int find(ElementType)const;
        int find(int,int,ElementType)const;
        int accumulate(int,int);
        void copy(int,int,int);
        int count(int, int, ElementType);
        void fill(int,int,ElementType);
        friend ostream & operator<<(ostream &,Array);
};
int Array::DefaultArraySize = 10; //initilaizing the static int
void Array::doublesize()
{
    ElementType * temp = new ElementType[2*size];
    for(int i = 0; i<size; i++)
    {
        temp[i] = data[i];
    }
    delete [] data;
    data = temp;
    size*=2;
}
Array::Array(int size):data(new ElementType[size]),size(size)
{
    //there is no body of array is required
}
Array::Array(ElementType * thisArray, int long thisArraySize):data(new ElementType[thisArraySize]),size(thisArraySize)
{
    for(int i = 0; i < size; i++)
    {
        data[i] = thisArray[i];
    }
}
Array::Array(const Array & a):data(new ElementType[a.size]),size(a.size)
{
    for(int i = 0; i < size; i++)
    {
        data[i] = a.data[i];
    }
}
Array::~Array()
{
    delete [] data;
    size = 0;
}
Array & Array:: operator=(const Array & a)
{
    if(this!=&a){
        this->data = new ElementType[a.size];
        this->size = a.size;
        for(int i = 0; i < size; i++)
            data[i] = a.data[i];
    }
    return *this;
}
bool Array::operator==(const Array & thisArray)
{
    if(this->size != thisArray.getSize())
        return false;
    else
    {
        for(int i = 0; i < size; i++)
            if(this->data[i] != thisArray.data[i])
                return false;
    }
    return true;
}
bool Array::operator!=(const Array & thisArray)
{
    if(this->size != thisArray.getSize())
        return true;
    else{
        for(int i = 0; i < size; i++)
            if(this->data[i] != thisArray.data[i])
                return true;
    }
    return false;
}
ElementType & Array::operator[](int index)
{
    if(index < 0){
        cout<<"Array Index "<<index<<" out of Bound"<<endl;
        exit(0);
    }
    if(index > size - 1)
        doublesize();
    return data[index]; //returning by refernce because we can use [] operator as l-value and r-value.
}
long Array::getSize()const{
    return size;
}
ElementType Array::min()const
{
    ElementType min = data[0];
    for(int i = 1; i<size; i++)
        min = min < data[i] ? min : data[i];
    return min;
}
ElementType Array::max()const
{
    ElementType max = data[0];
    for(int i = 1; i<size; i++)
        max = max > data[i] ? max : data[i];
    return max;
}
int Array::find(ElementType e)const
{
    for(int i = 0; i<size; i++)
    {
        if(data[i]==e)
            return i;
    }
    return -1;
}
int Array::find(int startIndex,int endIndex,ElementType thisElement)const
{
    for(int i = startIndex; i <= endIndex && endIndex<size; i++)
    {
        if(data[i] == thisElement)
            return i;
    }
    return -1;
}
int Array::accumulate(int startIndex,int endIndex)
{
    int sum = 0;
    for(int i = startIndex; i<=endIndex && endIndex<size; i++)
    {
        sum+=data[i];
    }
    return sum;
}
void Array::copy(int startIndex,int endIndex,int insertPointIndex)
{
    int diff = endIndex - startIndex + 1;
    ElementType * temp= new ElementType[size+diff];
    for(int i = 0; i < insertPointIndex; i++)
    {
        temp[i] = data[i];
    }
    int iterator = 0;
    for(int i = startIndex; i<=endIndex; i++)
    {
        temp[insertPointIndex+iterator] = data[i];
        iterator++;
    }
    int it2 = 0;
    for(int i = insertPointIndex+iterator; i<size+diff; i++)
    {
        temp[i] = data[insertPointIndex+it2];
        it2++;
    }
    delete [] data;
    data = temp;
    size = size + diff;
}
int Array::count(int startIndex,int endIndex,ElementType thisElement)
{
    int cnt = 0;
    for(int i = startIndex; i <= endIndex && endIndex<size; i++)
    {
        if(data[i] == thisElement)
            cnt++;
    }
    return cnt;
}
void Array::fill(int startIndex,int endIndex,ElementType fillElement)
{
    for(int i = startIndex-1; i<endIndex; i++)
    {
        data[i] = fillElement;
    }
}
ostream & operator<<(ostream & out, Array a)
{
    for(int i = 0; i<a.size; i++)
    {
        out<<a.data[i];
    }
    return out;
}
#endif // ARRAY_H_INCLUDED
