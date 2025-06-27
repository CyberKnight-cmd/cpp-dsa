#include<bits/stdc++.h>
using namespace std;

int majorityElementBrute(int arr[], int n){
    int range = n/2;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[i]==arr[j])
                count++;
        }
        if(count>range) return arr[i];
    }
    return -1;

    // Time Complexity : O(n^2)
    // Space Complexity : O(1)
}

int majorityElementBetter(int arr[], int n){
    map<int, int> frequencyHash;
    
    for(int i = 0; i < n; i++)
        frequencyHash[arr[i]]++;

    for (auto &&i : frequencyHash)
        if(i.second>n/2)    return i.first;
    
    return -1;
    // Time Complexity : O(2n)
    // Space Complexity : O(n)
}

int majorityElementOptimal(int arr[], int n){
    int element, count = 0;
    for(int i = 0; i < n; i++){
        if(!count){
            element = arr[i];
            count = 1;
        }
        else if(element==arr[i]) count++;
        else    count--;
    }

    // Verifying
    count = 0;
    for(int i = 0; i < n; i++)
        if(element==arr[i]) count++;

    if(count>n/2)   return element;
    else return -1;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // cout << majorityElementBrute(arr, n);
    // cout << majorityElementBetter(arr, n);
    cout << majorityElementOptimal(arr, n);

    return 0;
}

// 5 5 5 1 2 5 3 5 5 6 5 7 5 8 5 9 5 5 10 11
// 1 2 3 2 1 2 1 2 3 2 3 2 3 2 3 2 3 4 3  2 