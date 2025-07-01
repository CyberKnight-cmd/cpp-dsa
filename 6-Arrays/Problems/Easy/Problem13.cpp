/*
Remove Element

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
*/

#include<bits/stdc++.h>
using namespace std;

// For submission as the discussion says there is some problem with the testcases so they won't accept initial vectors unless the values mentioned are completely removed.
// Another fix that could've been possible was returning a vector with other elements but they aren't expecting that either (so the only possible thing to be done is this)
int removeElement(vector<int>& nums, int val) {
    nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
    return nums.size();
}

// For the actual solution, this returns the n-k elements where k is the number of occurences that were swapped, i.e. (n-k ) are the first initial elements that are valid (not maintained in order tho)
int removeElementProperly(vector<int>& nums, int val){
    int n = nums.size(), high = n-1, k = 0;    
    while(nums[high]==val && high>=0)
        high--;
    if(high==-1)    return high;
    for(int i = 0;i <= high ;i++){
        if(nums[i]==val){
            nums[i] = nums[high--];
            k++;
        }
    }
    for (auto &&r : nums)
        cout << r << " ";
    
    return n-k;
}

// Later on make a function to return a vector that contians no elements == 'val'

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << endl << removeElementProperly(nums, 2);
    return 0;
}