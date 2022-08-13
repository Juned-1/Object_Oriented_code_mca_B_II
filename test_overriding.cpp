#include<iostream>
class Base{
    public:
        virtual void func(){
            std::cout<<"Base"<<std::endl;
        }
};
class Derived : public Base{
    public:
        void func(){
            std::cout<<"Derived"<<std::endl;
        }
};
int main(){
    Base * b = new Derived();
    b->func();
    return 0;
}