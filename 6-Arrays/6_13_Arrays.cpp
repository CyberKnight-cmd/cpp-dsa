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

int longestConsecutiveSequenceBetter(int arr[], int n){
    quickSort(arr, 0, n-1);
    int count = 1, maxCount = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i-1] + 1){
            count++;
            maxCount = max(count, maxCount);
        }
        else if(arr[i]!=arr[i-1])
            count = 0;
    }
    return maxCount;
}


// O(3n)
// O(n)
int longestConsecutiveSequenceOptimal(int arr[], int n){
    if(n==0) return 0;
    unordered_set<int> array;
    for (int i = 0; i < n;i++)
        array.insert(arr[i]);
    int longest = 1;
    for (auto &&i : array)
    {
        if(array.find(i-1)==array.end()){
            int count = 1;
            int x = i;
            while (array.find(x+1)!=array.end())
            {
                x++;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;    
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
    // cout << longestConsecutiveSequenceBrute(arr,n);
    // cout << longestConsecutiveSequenceBetter(arr, n);
    cout << longestConsecutiveSequenceOptimal(arr, n);
    return 0;
}