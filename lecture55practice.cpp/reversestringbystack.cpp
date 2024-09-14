#include<iostream>
#include<stack>
using namespace std;

int main(){

    string a = "sagar";

    stack<char> s;

    for(int i =0; i< a.length(); i++){
        char ch = a[i];
        s.push(ch);
    }

    string ans = "";

    while (!s.empty()){
        char ch = s.top();
        ans.push_back(ch);

        s.pop();

    }

   cout << " output string is : " << ans;


}