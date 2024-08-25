#include<Iostream>
#include<vector>
using namespace std;

void permutations(int index, vector<string>& ans, string input ){
    
    if (index >= input.length()){
        ans.push_back(input);
        return ;
}
   for (int i = index ; i< input.length(); i++){
    swap(input[index],input[i]);
     permutations(index+1,ans,input);
     // backtrack of an array
         swap(input[index],input[i]);

     }
     
   
}

int main(){
    int index = 0;
    vector<string> ans;
    string input= "abc";
    permutations(index,ans,input);
      for(string s : ans){
        cout << s << "  ";
     }
    return 0;
}