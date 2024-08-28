#include<iostream>
#include<vector>
using namespace std;

void solve(int index, string mapping[], string digits, string output,vector<string>& ans){

    if(index >= digits.length() ){
        ans.push_back(output);
        return ;
    }
    int number = digits[index] - '0';
    string value = mapping[number];
   

    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
       
        solve(index+1,mapping,digits,output,ans );
        output.pop_back();
    }
  



}

int main(){
    vector<string> ans;
    string output;
    int index = 0;
    string digits = "34";
    string mapping[10]= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "uvw", "xyz"};
     solve(index,mapping,digits,output,ans);
   
    for (string s : ans){
        cout<< s << " ";
    }
   
    
    return 0;



}