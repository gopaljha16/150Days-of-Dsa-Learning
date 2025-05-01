#include <iostream>
using namespace std;

// Here we can say it is using the hierarchical inheritance and multiple inheritance
class Student{
    public:
    void print(){
       cout<<"I am Student"<<endl;
    }
};


class Male{
    public:
    void male(){
        cout<<"I am Male"<<endl;
    }
};

class Female{
    public:
    void female(){
        cout<<"I am Female"<<endl;
    }
};

class Boy : public Student , public Male{
    public:
    void BoyPrint(){
        cout<<"I am boy"<<endl;
    }
};

class Girl : public Student  , public Female{
    public:
    void GirlPrint(){
        cout<<"I am girl"<<endl;
    }
};

// Hybrid Inheritance
int main(){
    Boy B;
    B.BoyPrint();
    B.print();
}