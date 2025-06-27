/* 
# *Build Array from Permutation*
Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).


Example 1:

Input: nums = [0,2,1,5,3,4]
Output: [0,1,2,4,5,3]
Explanation: The array ans is built as follows: 
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]
Example 2:

Input: nums = [5,0,1,2,3,4]
Output: [4,5,0,1,2,3]
Explanation: The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] < nums.length
The elements in nums are distinct.
 

Follow-up: Can you solve it without using an extra space (i.e., O(1) memory)?
*/

// https://leetcode.com/problems/build-array-from-permutation/

#include<bits/stdc++.h>
using namespace std;

vector<int> buildArrayBrute(vector<int>& nums){
    // O(n) : Time Complexity
    // O(n) : Space Complexity
    if(nums.size()>1000)    return{};
    vector<int> newArray;
    for (int i = 0; i < nums.size(); i++)
        if(nums[i]<nums.size())  newArray.push_back(nums[nums[i]]);
    return newArray;
    
} 

/* This technique is sometimes called "value encoding" or "value flattening", and it relies on the fact that:

If all values are less than n, then x + y*n uniquely encodes (x, y).

Use this trick when : 
1. All numbers are within a small bounded range (like 0 to n-1)
2. You need to mutate the array but still require access to the original values later.
3. You're asked to solve it in-place or with O(1) extra space.
*/
void buildArrayOptimal(vector<int> &nums){
    int n = nums.size();
    
    // First pass: encode both original and new values
    for(int i = 0; i < n; i++){
        nums[i] = nums[i] + (nums[nums[i]] % n) * n;
    }

    // Second pass: extract only new values
    for(int i = 0; i < n; i++){
        nums[i] = nums[i] / n;
    }

    for (auto &&i : nums)
        cout << i << " ";
    
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    buildArrayOptimal(arr);
    
    return 0;
}