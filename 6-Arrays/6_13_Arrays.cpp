#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[],int n, int element){
    for(int i = 0; i < n; i++){
        if(element==arr[i])
            return true;
    }
    return false;
}

int longestConsecutiveSequenceBrute(int arr[], int n){
    int longest = 1;
    for(int i = 0; i < n; i++){
        int x = arr[i];
        int count = 1;
        while(linearSearch(arr,n,x+1)){
            x++;
            count++;
        }
        longest = max(count,longest);
    }
    return longest;
}

int placePivot(int arr[], int low, int high) {
    int pivot = arr[low];
    int left = low;
    int right = high;

    while (true) {
        // Move left pointer to the right until finding element >= pivot
        while (left <= high && arr[left] < pivot)
            left++;

        // Move right pointer to the left until finding element <= pivot
        while (right >= low && arr[right] > pivot)
            right--;

        // Check if pointers have crossed
        if (left >= right)
            return right;

        // Swap elements at left and right
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}


void quickSort(int arr[], int low, int high){
    if(low<high){
        int partitionIndex = placePivot(arr,low,high);
        quickSort(arr,low,partitionIndex-1);
        quickSort(arr,partitionIndex+1,high);
    }
}

int longestConsecutiveSequenceBrute(int arr[], int n){
    quickSort(arr, 0, n-1);
}
int main(){
    int n;
    cin >> n;
    int arr[n]; 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // vector<int> leaders = longestConsecutiveSequence(arr, n);
    // for (auto &&i : leaders)
        // cout << i << " ";   
    cout << longestConsecutiveSequenceBrute(arr,n);
    return 0;
}