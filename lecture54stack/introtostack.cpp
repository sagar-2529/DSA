#include<iostream>
using namespace std;

class stack {
     // properties
     public:
     int size;
     int top;
     int* arr;


     stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;

     }

        void push(int element) {
            if ( size - top > 1){
                top++;
                arr[top] = element;
            }
            else{
                cout << " stack overflow" << endl;
            }
        }
        void pop(){
            if ( top != -1){
                top--;
            }
            else{
                cout << "stack underflow " << endl;
            }
        }
        int peek(){
            if ( top >= 0 ){
                return arr[top];
            }
            else{
                cout << " stack is empty " << endl;
                return -1;
            }
        }
        bool isempty(){
            if ( top == -1){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){

    //  // creation of stack
    //  stack<int> s;
      
    // // add element in it
    //  s.push(7);
    //  s.push(9);
     
    //  // remove an element
    //  s.pop();

    //  cout << " top element of stack : "<< s.top() << endl;

    // // check list is empty or not
   
    stack sa(5);

    sa.push(5);
    sa.push(7);
    sa.push(5);
    sa.push(7);
    sa.push(5);

    sa.pop();
    sa.pop();
    sa.pop();
    sa.pop();
    sa.pop();
     if(sa.isempty()){
         cout << " stack is empty " << endl;
     }
      else{
       cout << " stack is non empty ";
    }

    cout << sa.peek();



}