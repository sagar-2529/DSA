#include<iostream>
#include<vector>
using namespace std;
bool is_safe(vector<vector<int>>& visited, int x, int y, vector<vector<int>>& m,int n){
    if( ( x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y] == 0) && m[x][y] == 1){
        return true;
    }
    else{
        return false;
        }
}

void solve(vector<string>& ans, vector<vector<int>>& visited, string output, int x, int y, int n, vector<vector<int>>& m){
    if(x == n-1 && y == n-1){
        ans.push_back(output);
        return;
    
    }
    visited[x][y] = 1;
    // right move
    int newx = x;
    int newy = y+1;
    if(is_safe(visited,newx,newy,m,n)){
         solve(ans,visited,output+'R',newx,newy,n,m);

    }

     newx = x;
     newy = y-1;
    if(is_safe(visited,newx,newy,m,n)){
        solve(ans,visited,output + 'L',newx,newy,n,m);
    }

     newx = x+1;
     newy = y;
    if(is_safe(visited,newx,newy,m,n)){
         solve(ans,visited,output+ 'D',newx,newy,n,m);
    }

    
     newx = x-1;
    newy = y;
    if(is_safe(visited,newx,newy,m,n)){
         solve(ans,visited,output + 'U',newx,newy,n,m);
       
    }
    visited[x][y] = 0;
 }
int main(){
   vector<string> ans;
  int n;
  cout << "size of n is : ";
  cin>> n;
   vector<vector<int>> m(n, vector<int>(n));
   vector<vector<int>> visited(n, vector<int>(n, 0));

    cout << " enter maze matrix: ";
  for(int i =0 ; i<n; i++){
    for(int j=0; j<n; j++){
        cin >> m[i][j] ;
    }
}
for(int i =0 ; i<n; i++){
    for(int j=0; j<n; j++){
        visited[i][j] == 0;
    }
}
 string output= "" ;
 int x = 0;
 int y = 0;
 solve(ans,visited,output,x,y,n,m);
 for( string s: ans){
    cout << s << " ";
 }
  }
