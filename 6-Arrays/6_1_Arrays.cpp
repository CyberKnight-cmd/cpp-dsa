#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n, string s = ""){
    cout << endl << s;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void swapp(int arr[], int i, int j){
    int t = arr[i];
    arr[i]= arr[j];
    arr[j] = t;
}

// T.C : O(n) S.C : O(1)
int largestElement(int arr[], int n){
    int max = INT_MIN;
    for(int i = 0; i < n; i++)
        if(arr[i]>max) max = arr[i];
    return max;
}

int secondLargest(int arr[], int n){
    pair<int,int> max = {arr[0], INT_MIN};
    for(int i = 1; i < n; i++){
        if(arr[i]>max.first){
            max.second = max.first;
            max.first = arr[i];
        }
        else if(arr[i]>max.second && arr[i]<max.first)
            max.second = arr[i];
    }
    return max.second;
}


// Checking if given array is sorted using recursion
bool isSorted(int arr[], int n, bool checkForAscending = true, int i = 0){
    if(i==n-1) return true;


    if(((arr[i]>arr[i+1]) && checkForAscending) || ((arr[i]<arr[i+1]) && !checkForAscending))   return false; 
    
    return isSorted(arr,n,checkForAscending,i+1);
}
// Brute force 
int uniqueElementsBruteForce(int arr[], int n){
    set<int> st;
    // First pass
    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }
    // Second pass
    int index = 0;
    for(auto it : st)
        arr[index++] = it;

    return st.size();
}
// Optimal
int uniqueElementsOptimal(int arr[], int n){
    int i = 0;
    for(int j = 0; j < n; j++)
        if(arr[j] != arr[i]){
            swapp(arr,i+1,j);
            i++;
        }
    return (i+1);
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // cout << boolalpha << isSorted(arr, n, true);
    // cout << uniqueElementsBruteForce(arr, n);
    cout << uniqueElementsOptimal(arr, n);
    printArray(arr, n, "Printing the array : ");
    return 0;
}