#include<iostream>
#include<vector>
using namespace std;

void solve(string a,vector<vector<string>>& ans,vector<string>& output, int index ){
    if(index >= a.size()){
        ans.push_back(output);
        return ;
    }

    // include
    output.push_back(string(1,a[index]));
    solve(a, ans,output,index+1);

     output.pop_back();
   
   // exclude
    solve(a, ans,output,index+1);

    

}



int main(){

    vector<vector<string>> ans;
    vector<string> output;
    string a = "abc";
    int index = 0;
    solve(a, ans, output,index);
    for(int i = 0; i < ans.size(); i++) {
        cout << "{ ";
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

}