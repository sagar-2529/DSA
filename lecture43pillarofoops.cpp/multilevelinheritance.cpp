#include<iostream>
using namespace std;

class animal{
    public:
    int weight;
    int height;

    void speak(){
        cout << "speaking "<< endl;
    }

};
class dog : public animal{

};

int main(){

    dog tommy;
    tommy.speak();

}