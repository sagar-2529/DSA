// count inversion using merge sort
#include<iostream>
using namespace std;

int merge(int* arr, int s, int e) {
    int inversion =0;
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* first = new int[len1];
    int* second = new int[len2];

    // Copy data to temporary arrays
    for (int i = 0; i < len1; i++) {
        first[i] = arr[s + i];
    }
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mid + 1 + i];
    }

    // Merge the temporary arrays back into arr[s..e]
    int index1 = 0; // Initial index of first subarray
    int index2 = 0; // Initial index of second subarray
    int mainindexarray = s; // Initial index of merged subarray

    while (index1 < len1 && index2 < len2) {
        if (first[index1] <= second[index2]) {
            arr[mainindexarray++] = first[index1++];
        } else {
            inversion = inversion + len1 -index1;
            arr[mainindexarray++] = second[index2++];
           
        }
    }

    // Copy any remaining elements of first[]
    while (index1 < len1) {
        arr[mainindexarray++] = first[index1++];
    }

    // Copy any remaining elements of second[]
    while (index2 < len2) {
        arr[mainindexarray++] = second[index2++];
    }
    return inversion;

    // Free the dynamically allocated memory
    delete[] first;
    delete[] second;
}

int mergesort(int* arr, int s, int e) {
    if (s >= e) {
        return 0; // Base case: If the array has one or zero elements, it's already sorted
    }
   


    int mid = (s + e) / 2;

    int inversion = 0;

    // Sort the first and second halves

    inversion = inversion + mergesort(arr, s, mid);
    inversion = inversion + mergesort(arr, mid + 1, e);

   

    // Merge the sorted halves
   inversion = inversion+  merge(arr, s, e);

   return inversion;
    
  
}

int main() {
    int arr[5] = {5,4,3,2,1};

    cout << " no of inversions is : ";
        
    cout << mergesort(arr, 0, 4);
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    

    cout << endl;
    return 0;
}
