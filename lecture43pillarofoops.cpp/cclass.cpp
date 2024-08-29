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

class male : public human{
    string colour;

    void sleep(){
        cout << " man is sleeping : ";
    }
};

int main(){

   male;

}