#include<Iostream>
#include<vector>
using namespace std;

int find_next_min(vector<int> &v,vector<int> &ans){
     
     bool a = true;
     for(int i=0; i<v.size(); i++){
        a=true;
        for(int j=i+1; j<v.size(); j++){
            if(v[j] < v[i]){
                ans.push_back(v[j]);
                a = false;
                break;
            }
        }
        if( a == true){
         ans.push_back(-1);
        }
     }
}

int main(){
    vector<int> v;
    v.push_back(6);
    v.push_back(7);
    v.push_back(4);
    v.push_back(5);
    v.push_back(8);

    v[3] = 2;

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    vector<int> ans;

    cout << endl;

    find_next_min(v,ans);

     for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

}