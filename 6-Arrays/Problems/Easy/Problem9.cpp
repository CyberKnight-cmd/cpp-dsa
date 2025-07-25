/*
Frequency of the most frequent element

The frequency of an element is the number of times it occurs in an array.

You are given an long longeger array nums and an long longeger k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

 

Example 1:

Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
Example 2:

Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
Example 3:

Input: nums = [3,9,6], k = 2
Output: 1
 

Constralong longs:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= k <= 105
*/

#include<bits/stdc++.h>
using namespace std;


int frequency(vector<int> &nums, long long k){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int left = 0, right = 0, windowLen = right - left + 1, maxFreq = 0;
    long total = 0;
    while(right<n){
        total+= nums[right];
        // Decreasing the window if invalid
        while(nums[right]*windowLen > total + k){
            total -= nums[left++];
            windowLen--;
        }
        maxFreq = max(windowLen, maxFreq);
        right++;
        windowLen++;
    }

    return maxFreq;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << frequency(arr, k);
    return 0;
}