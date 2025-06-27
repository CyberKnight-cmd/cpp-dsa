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
// Time Complexity : O(n^2)
void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++)
            if (arr[j] < arr[min]) min = j;
        if (min!=i) swapp(arr, min, i);
    }
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    printArr(arr, n, "Before sorting : ");

    selectionSort(arr, n);
    printArr(arr, n, "\nAfter sorting : ");
    return 0;
}