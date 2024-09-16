#include<Iostream>
#include<stack>
using namespace std;


void sort(stack<int> &s, int e){

    if(s.empty() || e>s.top()){
       s.push(e);
       return ;
    }
   
        int top = s.top();
        s.pop();

        sort(s,e);
        s.push(top);
    }

void sortstack(stack<int> &s){
    if(s.empty()){
        return;
    }

     int top = s.top();
     s.pop();

     sortstack(s);
     sort(s,top);
}

int main(){
    stack<int> s;
    s.push(-7);
    s.push(11);
    s.push(9);
    s.push(-5);
    s.push(3);

   cout << endl;

   sortstack(s);
   
   while(!s.empty()){
      cout << s.top() << " ";
      s.pop();
   }



}