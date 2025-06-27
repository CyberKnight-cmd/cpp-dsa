#include<bits/stdc++.h>
using namespace std;
using namespace std :: chrono;

int findMissingNumberBrute(vector<int> &arr, int n){
    // Use Linear Search
    for(int i = 1; i <= n; i++){
        int flag = 0;
        for(int it : arr)
            if(it == i){
                flag = 1;
                break;
            }
        if(!flag) return i;
    }
    return -1;

    // Time Complexity : O(n^2)
    // Space Complexity : O(1)
}

int findMissingNumberBetter(vector<int> &arr, int n){
    // Use Hashing
    int hash[n + 1] = {0};
    // Pre-compute
    for (auto &&i : arr)
        hash[i]++;
    
    for(int i = 1; i <= n; i++)
        if(!hash[i]) return i;
    return -1;
}

int findingMissingNumberOptimal(vector<int> &arr, int n){
    /*
    *Will be good for small integers but for bigger integers, it will require slighlty more space.

    int actualSum = 0, expectedSum = (n*(n+1))/2;
    for (auto &&i : arr)
        actualSum += i;
    
    return expectedSum - actualSum;
    */

    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < n-1; i++){
        xor2 ^= arr[i];
        xor1 ^=  (i+1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}

int maximumConsecutiveOnes(vector<int> &arr){
    int maxCount = 0, count = 0;
    for (int i =0; i < arr.size();i++)
    {
        if(arr[i]==1){
            count++;   
            maxCount = count>maxCount ? count : maxCount;
        } 
        else count = 0;
    }
    return maxCount;
    
}

int numberThatAppearsOnceAndTheOthersTwiceBrute(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[i]==arr[j])
                count++;
        }
        if (count==1) return arr[i];
    }
    return 0;
    // Time Complexity : O(n^2)
    // Space Complexity : O(1)
}

int numberThatAppearsOnceAndTheOthersTwiceBetter(vector<int> &arr){
    map<int, int> mpp;
    for (auto &&i : arr)
        mpp[i]++;
    
    for (auto &&it : mpp)
        if(it.second == 1) return it.first;

    return 0;
    // Time Complexity : O(NlogM) + O(N/2 + 1)
    // Space Complexity : O(N/2 + 1)   
}


int numberThatAppearsOnceAndTheOthersTwiceOptimal(vector<int> &arr){
    int XOR1 = 0;
    for (auto &&i : arr)
        XOR1 ^= i;
    return XOR1;
    // O(n) --> Time Complexity
    // O(1) --> Space Complexity
}

int main(){
    // vector<int> arr = {1,4,3,5, 1, 1};
    // cout << findMissingNumberBrute(arr, 5) << " is not present" << endl;
    // cout << findMissingNumberBetter(arr, 5) << " is not present" << endl;
    // cout << findingMissingNumberOptimal(arr, 5) << " is not present" << endl;

    // cout << maximumConsecutiveOnes(arr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << numberThatAppearsOnceAndTheOthersTwiceBrute(arr)<<endl;
    cout << numberThatAppearsOnceAndTheOthersTwiceBetter(arr)<<endl;
    cout << numberThatAppearsOnceAndTheOthersTwiceOptimal(arr)<<endl;
   return 0;
}