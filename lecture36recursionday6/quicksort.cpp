#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int count = 0;

    for(int i = s + 1; i <= e; i++) {
        if(arr[i] < pivot) {
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;
    while(i < pivotIndex && j > pivotIndex) {
        while(arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quicksort(int arr[], int s, int e) {
    if(s >= e) {
        return;
    }

    int p = partition(arr, s, e);

    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}

int main() {
    int arr[5] = {1, 5, 3, 4, 7};

    quicksort(arr, 0, 4);

    for(int i = 0; i < 5; i++) {
        cout << arr[i] << "  ";
    }

    return 0;
}
