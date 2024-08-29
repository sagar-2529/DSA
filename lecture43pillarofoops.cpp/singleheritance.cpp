#include<iostream>
using namespace std;

class animal{
    public:
    int weight;
    int height;

    void bark(){
        cout << "barking "<< endl;
    }

};

class human{
    public : 
    string color;

    void speak(){
        cout << " speaking " << endl;
    }
};

class hybrid : public human, public animal{

};



int main(){

    hybrid h1;
    h1.speak();
    h1.bark();


    



}