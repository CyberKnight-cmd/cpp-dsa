#include<bits/stdc++.h>
using namespace std;

int maximumSubarraySumBrute(int arr[], int n){
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++)
                sum += arr[k];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int maximumSubarraySumBetter(int arr[], int n){
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];                
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int maximumSubarraySumOptimal(int arr[], int n){
    int max = INT_MIN, sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > max)   max = sum;
        if(sum < 0) sum = 0;
    }
    return max;
}

pair<int, int> maximumSubarraySum(int arr[], int n){
    int max = INT_MIN, sum = 0, start = -1;
    pair<int, int> range;
    for(int i = 0; i < n; i++){
        if(sum==0) start = i;
        sum += arr[i];
        if(sum>max){
            max = sum;
            range.first = start;
            range.second = i+1;
        }
        if (sum<0) sum = 0;
    }
    return range;
}
int main(){
    // Maximum Subarray Sum
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << maximumSubarraySumBrute(arr, n) << endl;
    cout << maximumSubarraySumBetter(arr, n) << endl;
    cout << maximumSubarraySumOptimal(arr, n) << endl;
    pair<int, int> getRange =  maximumSubarraySum(arr, n);
    cout << getRange.first << ", " << getRange.second;
    return 0;
}