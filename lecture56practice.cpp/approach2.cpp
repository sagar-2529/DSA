// 2nd approach of next smaller element 
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {2,1,4,3};
    vector<int> ans(4);

    stack<int> s;
    s.push(-1);
    
    for(int i= 3; i>=0; i--){
           
           int e = arr[i];
         while(s.top() >=  e){
                s.pop();
            }

            ans[i] = s.top();
            s.push(e); 
        
    }

for(int i=0; i<4; i++){
    cout << ans[i] << "  ";
}



}