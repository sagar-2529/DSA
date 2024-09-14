#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){

    int mid = (s+e)/2;
   
   int n1 = mid - s +1;
   int n2 = e - mid;

   int *arr1 = new int[n1];
   int *arr2 = new int[n2];

   int k = s;

   for(int i =0 ; i < n1; i++){
    arr1[i] = arr[k++];
   }
    
    k = mid+1;
   
   for(int i =0 ; i < n2; i++){
    arr2[i] = arr[k++];
   }
   int i = 0;
   int j = 0;
   int m = s;

   while( i < n1 && j < n2){
    if( arr1[i]< arr2[j]){
        arr[m++] = arr1[i++];
    }
    else{
        arr[m++]= arr2[j++];
    }
   }
   while( i < n1 ){
     arr[m++] = arr1[i++];
   }
    while( j < n2 ){
     arr[m++] = arr2[j++];
   }

}

void mergesort(int arr[], int s, int e){
     
     if(s >= e){
        return ;
     }
    int mid = (s+e)/2;

    mergesort(arr,s,mid);

    mergesort(arr,mid+1,e);

    merge(arr,s,e);



}

int main(){

    int arr[5]= {1,2,3,4,5};

    mergesort(arr,0,4);

    for(int i=0; i< 5; i++){
        cout << arr[i]<< "  ";
    }



    return 0;
}