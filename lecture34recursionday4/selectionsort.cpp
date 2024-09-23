// selection sort using recursion
#include<iostream>
using namespace std;

void selection_sort(int *arr, int n){
    
       
    if(n<=1){
        return ;
    }
   
    int minindex = 0;
    for( int i = 1; i< n; i++){
        if(arr[i] < arr[minindex]){
            minindex = i;
        }
        swap (arr[0], arr[minindex]);
     
    }
     selection_sort(arr +1, n-1);
}
int main(){
    int arr[5]={5,4,3,2,1};
    selection_sort(arr,5);
    for( int i=0; i<5; i++){
        cout<< arr[i]<< " ";
    }
}

