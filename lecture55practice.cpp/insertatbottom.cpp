#include<iostream>
#include<stack>
using namespace std;

void insert_an_element(stack<int> &a, int size, int count, int e){
     
     if(count == 0){
        a.push(e);
        return;
     }
     int no = a.top();
     a.pop();
     insert_an_element(a,size,count -1,e);
     a.push(no);
     
}

int main(){
    string a = "2345";
    stack<int> s;
    int b = 0;
    for(int i=0; i<a.length(); i++){
        b = a[i] - '0';
        s.push(b);
    }
    int count = s.size();
    int element;
    cin >> element;
    insert_an_element(s,s.size(),count,element);

    stack<int> tempstack = s;
    
    while(!tempstack.empty()){
        cout << tempstack.top() << " ";
        tempstack.pop();
    }


      
}