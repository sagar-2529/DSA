#include<iostream>
using namespace std;

void reverse_string(string arr[], int s, int e){
    if(s>e){
        return ;
    }
    swap(arr[s],arr[e]);
    reverse_string(arr,s+1,e-1);
}
int main(){
    string arr[4]= {"s", "a", "g", "a"};
    reverse_string(arr,0,3);
    for(int i=0; i<4; i++){
        cout<< arr[i]<< " ";
    }
}