/*
Rotate Array

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/

#include<bits/stdc++.h>
using namespace std;

// O(2n) : Time
// O(n) : Space
void rotateRightBrute(vector<int> &arr, int k){
    int n = arr.size();
    k = k%n;
    vector<int> temp(n);
    
    for(int i = 0; i < n; i++){
        temp[(i+k)%n] = arr[i];
    }

    for(int i = 0; i<n;i++){
        arr[i] = temp[i];
        cout << arr[i] << " ";
    }
}

void rev(int *start, int *end){
    end--;
    while(start<end){
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void rotateRight(vector<int> &arr, int k){
    int n = arr.size();
    rev(arr.data()+(n-k), arr.data() + n);
    rev(arr.data(), arr.data()+(n-k));
    rev(arr.data(), arr.data()+n);
    for(int i = 0; i<n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    rotateRight(arr, k);
    return 0;
}