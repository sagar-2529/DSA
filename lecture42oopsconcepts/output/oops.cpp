#include<iostream>
#include<cstring>
using namespace std;

class hero {
    public:
    int health = 70 ;
    char level = 'B';
    static int timetocomplete;

    char* name;

    hero(){
        cout << " simple comstructor called " << endl;
        name = new char[100];
    }

    hero(int health, char level){
        cout << "-> this"<< this << endl;
        this -> health = health;
        this -> level = level;
       
    }
    hero ( hero& temp){

        char* ch = new char[strlen(temp.name) + 1];
         strcpy(ch, temp.name);
         this -> name = ch;
        cout << "copy constructor called " << endl;
         this -> health = temp.health;
         this -> level = temp.level;
        
    }


    int gethealth(){
        return health;
    }

     int sethealth(int h){
        health = h;
    }

    char getlevel(){
        return level;
    }
    char setlevel(char a){
        level = a;
    }
    void print(){
        cout<< " name is : "<< this-> name<< endl;
        cout << " health is : " << this-> health << endl;
        cout << " level is : " << this-> level << endl;
    }

    void setname(char name[]){
        strcpy(this-> name , name);
    }
    // called destrcutor
    ~hero(){
        cout << " destructor called  " <<endl;
    }
    static int random(){
        return timetocomplete ;
    }

};

int hero:: timetocomplete = 5;

int main(){
   // static allocation

    //  cout << ramesh.health << endl;
    //   cout << "health of hero is : " <<  ramesh.gethealth() << endl;
    //   ramesh.sethealth(85);
    // cout << ramesh.level << endl;
    // cout << "health of hero is : " << ramesh.health << endl;
    
    // cout << " hi "<< endl;
   // dynamically allocate
    // hero* b = new hero();

    // cout << endl;
    //  b->sethealth(99);
    //  b->setlevel('C');

    //  cout << (*b).health<< endl;
    //  cout << b->level << endl;

    // hero ramesh(20,'D');
    // cout << " adress of ramesh : "<< &ramesh << endl;
    // cout << ramesh.health << endl;
    // cout << ramesh.level << endl;

    // hero *b = new hero(11,'A');
    // cout << b->health << "  " << b->level;

    // hero S(80,'A');
    // S.print();

    // // copy constructor
    // hero R(S);
    // R.print();

    // hero h1;
    // h1.sethealth(12);
    // h1.setlevel('X');
    // char name[9] = "msdhoni";
    // h1.setname(name);
    //  h1.print();

    //  hero h2(h1);
    //  h2.print();

    //  h1.name[0]='k';
    //  h1.print();
    //  h2.print();

    hero h1;
    hero* h2 = new hero();
    delete h2;

    cout << hero::timetocomplete << endl;

   cout << hero::random() << endl;







   


   


}
