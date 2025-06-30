/*
Move Zeroes

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1

Follow up: Could you minimize the total number of operations done?
*/

#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums){
    // Searching for first 0
    int i = 0, n = nums.size();
    for(i = 0;i < n;i++)
        if(!nums[i])
            break;
    if(i==n)    return;
    // Starting off from the next 0
    for(int j = i + 1; j<n; j++){
        if(nums[j])
            swap(nums[i++], nums[j]);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    moveZeroes(nums);
    return 0;
}