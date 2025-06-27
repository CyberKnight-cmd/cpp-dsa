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

// Time complexity : O(n^2)
// void bubbleSort(int arr[], int n) {
//     for (int i = n - 1; i >= 0; i--) {
//         bool didSwap = false;
//         for (int j = 0; j < i; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 swapp(arr, j, j + 1);
//                 didSwap = true;
//             }
//         }
//         if (!didSwap)
//             break;
//     }
// }


// Fully recursive bubble sort with early exit.
void bubbleSort(int arr[],int n, int index = 0, bool swapped = false){
    if(n<=1) return;

    // Compare and swap a single pair at position index
    if(arr[index]>arr[index+1]){
        swapp(arr,index,index+1);
        swapped = true;
    }

    // increment for inner loop
    if (index + 1 < n - 1)
        bubbleSort(arr, n, index + 1, swapped);
    
    // End of one inner loop and the whole array remains unswapped indicates it's a sorted array so we exit early
    else if(!swapped) return;
    else bubbleSort(arr,n-1,0, false); // incrementing outer loop
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    printArr(arr, n, "Before sorting : ");

    bubbleSort(arr, n);
    printArr(arr, n, "\nAfter sorting : ");
    return 0;
}