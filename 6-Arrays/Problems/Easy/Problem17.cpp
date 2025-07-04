/*
Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include<bits/stdc++.h>
using namespace std;

// Brute Force Method
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(nums[i]+nums[j]==target)
                return {i,j};
        }
    }
    return {-1};
}

//Better Method
vector<int> twoSumss(vector<int>& nums, int target) {
    int n = nums.size();

    // Pair each element with its original index
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++){
        arr.push_back({nums[i], i});
    }

    // Sort the array based on values
    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    while(left < right){
        int sum = arr[left].first + arr[right].first;
        if(sum == target){
            // Return original indices
            return {arr[left].second, arr[right].second};
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }

    // If no solution found (problem guarantees one exists)
    return {};
}

// Optimal
vector<int> twoSums(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> hash;
    // O(n)
    for(int i = 0; i < n; i++){
        hash[nums[i]] = i;
        int rem = target - nums[i];
        if(hash.find(rem) != hash.end())
            return {i, hash[rem]};
    }
}




int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> pairs =  twoSums(nums, target);
    for (auto &&i : pairs)
        cout << i << " ";   
}