#include<bits/stdc++.h>
using namespace std;



void swapp(int arr[], int i, int j){
    arr[i] += arr[j];
    arr[j] = arr[i] - arr[j];
    arr[i] -= arr[j];
}

void printArr(int arr[], int n, string s = ""){
    cout << s;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

// Time complexity
void insertionSort(int arr[], int n) {
    for(int i = 0; i < n; i++){
        int j = i;
        while (j>0 && arr[j-1] > arr[j])
        {
            swapp(arr, j, j-1);
            j--;
        }
    }
}

void insertionSortRecursive(int arr[], int n, int i = 1, int j = -1){
    if(i == n) return;

    if(j == -1) {
        insertionSortRecursive(arr, n, i, i);
        return;
    }

    if(j == 0 || arr[j - 1] <= arr[j]) {
        insertionSortRecursive(arr, n, i + 1, -1);
    }
    else {
        swapp(arr, j - 1, j);
        insertionSortRecursive(arr, n, i, j - 1);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    printArr(arr, n, "Before sorting : ");

    insertionSortRecursive(arr, n);
    printArr(arr, n, "\nAfter sorting : ");
    return 0;
}