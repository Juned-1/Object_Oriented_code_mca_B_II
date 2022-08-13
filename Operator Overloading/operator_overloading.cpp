#include<iostream>
using namespace std;
class Index{
    private:
        int value;
    public:
        Index(int = 0);
        inline int getIndex() const;
        void nextIndex();
};
Index::Index(int value){
    this->value = value;
}
inline int Index::getIndex() const{
    return value;
}
void Index::nextIndex(){
    value+=1;
}
int main(){
    Index idx1,idx2;
    cout<<"Index 1 = "<<idx1.getIndex()<<endl;
    cout<<"Index 2 = "<<idx2.getIndex()<<endl;
    idx1.nextIndex();
    idx2.nextIndex();
    idx2.nextIndex();
    cout<<"Index 1 = "<<idx1.getIndex()<<endl;
    cout<<"Index 2 = "<<idx2.getIndex()<<endl;
    return 0;
}