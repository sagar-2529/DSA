#include<Iostream>
using namespace std;

int max_area(int arr[], int n){
     int breadth = 1;
     int area = 0;
     int ans = 0;
    for(int i=0; i<n; i++){
      breadth = 1;
      int element = arr[i];
      int j = i;
     
      while((j+1) < n && arr[j+1] >= element){
        breadth = breadth +1;
        j++;
      }
     
      int m = i;
      
      while( (m-1) >= 0 && arr[m-1] >= element){
        breadth++;
        m--;
      }
      
      area = arr[i] * breadth;
      //cout << breadth << " ";
      
      if(area > ans){
        ans = area;
      }
      //cout << ans << "  ";

    }
    return ans;

}

int main(){
    int n = 11;
    int arr[11]= {2,5,2,4,5,2,7,3,9,8,10};

    int a = max_area(arr,n); 
    cout << a;
    
}