#include<iostream>
#include<vector>
using namespace std;

int main(){
int n;
cin >> n;
vector<vector<int>> m(n, vector<int>(n));
   vector<vector<int>> visited(n, vector<int>(n, 0));

for(int i =0 ; i< m.size(); i++){
    for(int j=0; j<m.size(); j++ ){
    cout << m[i][j];
    }cout << endl;
}

cout << endl;

}