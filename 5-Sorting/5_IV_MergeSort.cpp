#include<bits/stdc++.h>
using namespace std;


void printArr(vector<int> &arr, string s = ""){
    cout << s;
    for(auto it : arr)
        cout << it << " ";
}


// Merge Sort for Ascending order
// void mergeParts(vector<int> &arr, int low, int mid, int high){
//     vector<int> temp;
//     // [low...mid]
//     // [mid+1..high]
//     int left = low, right = mid + 1;
//     while (left<=mid && right<=high){
//         if (arr[left] <= arr[right])
//             temp.push_back(arr[left++]);
//         else
//             temp.push_back(arr[right++]);
//     }
//     while (left <= mid)
//         temp.push_back(arr[left++]);
//     while (right <= high)
//         temp.push_back(arr[right++]);
//     for(int i = low; i <= high; i++){
//         arr[i] = temp[i-low];
//     }
// }


// Merge Sort for Descending Order
void mergeParts(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    // [low...mid]
    // [mid+1..high]
    int left = low, right = mid + 1;
    while (left<=mid && right<=high){
        if (arr[left] >= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);
    for(int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }
}


void mergeSort(vector<int> &arr, int low, int high){
    if(low>=high) // base case
        return;
    
    int mid = (low + high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergeParts(arr, low, mid, high);
}



int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    printArr(arr, "Before sorting : ");

    mergeSort(arr, 0, n-1);
    printArr(arr, "\nAfter sorting : ");
    return 0;
}