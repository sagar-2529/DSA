#include<Iostream>
using namespace std;

class human{
    public:
    int height;
    int age;
    int weight;

    public:
    int getage(){
        return this-> age;
        
     }
     int set_weight(int w){
        this -> weight = w;
     }


};

class male : protected human{
    public : 
    string colour;

    void sleep(){
        cout << " man is sleeping  ";
    }

    int getheight(){
        return this-> height;
    }
};

int main(){

    male m1;
    cout << m1.getheight();




//    male object1;
//    cout << object1.height<< endl;

//    object1.set_weight(102);
//    cout << object1.weight << endl;

//    object1.sleep();

}