#include<iostream>
using namespace std;

class A{
    public:
    void func1(){
        cout << " inside function 1"<< endl;
    
    }

};
class B{
     public:
    void func2(){
        cout << " inside function 2"<< endl;
    
    }

};
class C : public A, public B{
     public:
    void func3(){
        cout << " inside function 3"<< endl;
    
    }

};
class D :  public C{
     public:
    void func4(){
        cout << " inside function 4"<< endl;
    
    }

};
int main(){
    // A ob1;
    // ob1.func1();
    // C ob2;
    // ob2.func3();
    // ob2.func1();
    D ob3;
    ob3.func1();
    ob3.func2();
    ob3.func3();
    ob3.func4();

    
}