#include<Iostream>
#include<vector>
using namespace std;

bool issafe(int x, int y, int n){
    if (( x >=0 && x<n) && (y>=0 && y<n)){
        return true;
    }
    return false;
}

void solve(int x,int y, string output, int n,vector<string>& ans){
    if (( x == n-1) &&( y == n-1 )){
        ans.push_back(output);
        return ;
    }
     
    
    //  for right move
      int newx = x;
      int newy = y + 1;
    if (issafe(newx,newy,n)){
        solve(newx,newy,output+ 'R',n,ans);
       }

    // for down move
    newx = x + 1;
    newy = y; 
    if (issafe(newx,newy,n)){
        solve(newx,newy,output+'D',n,ans);
    }

}

int main(){

    int n;
    cout << " enter size of matrix : ";
    cin >> n;
        string output = "";
        vector<string> ans;
        int x = 0;
        int y = 0;
        solve(x,y,output,n,ans);

        for(string s: ans){
            cout << s << endl;
        }

        

   

    return 0;
}