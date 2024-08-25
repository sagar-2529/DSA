#include<iostream>
using namespace std;

bool check_palindrome(string str,int s, int e){
    if(s > e){
        return true;
    }
    if(str[s]!= str[e]){
        return false;
    }
    s++;
    e--;
    return check_palindrome(str,s,e);
    
}

int main(){

    string name = "sagar";
    int ans = check_palindrome(name,0,4);
    if(ans==0){
        cout<< " the given string is not in palindrome"<< endl;
    }
    else{
        cout<< " given string is in palindrome ";
    }
    return 0;
}