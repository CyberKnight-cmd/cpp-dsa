#include<bits/stdc++.h>
using namespace std;


void printArr(vector<int> &arr, string s = ""){
    cout << s;
    for(auto it : arr)
        cout << it << " ";
}

// Quick Sort for Ascending order
// int placePivot(vector<int> &arr, int low, int high){
//     int pivot = arr[low];
//     int i = low + 1, j = high;
//     while (i<j)
//     {
//         while (arr[i] <= pivot && i <= high - 1)
//             i++;
    
//         while (arr[j] > pivot && j >= low + 1)
//             j--;
        
//         if(i<j) swap(arr[i],arr[j]);
//     }
//     swap(arr[low], arr[j]);
//     return j;
// }


// Quick Sort for Descending order.
int placePivot(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low, j = high;
    while (i<j)
    {
        while (arr[i] > pivot && i <= high - 1)
            i++;
    
        while (arr[j] <= pivot && j >= low + 1)
            j--;
        
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}


void quickSort(vector<int> &arr, int low, int high){
    if(low<high){
        int partitionIndex = placePivot(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    printArr(arr, "Before sorting : ");

    quickSort(arr, 0, n-1);
    printArr(arr, "\nAfter sorting : ");
    return 0;
}