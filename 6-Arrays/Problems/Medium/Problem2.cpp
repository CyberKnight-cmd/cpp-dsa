/*
75. Sort Colors

Given an array arr with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: arr = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: arr = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == arr.length
1 <= n <= 300
arr[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/


// Dutch National Flag Algorithm
// 0 --> low : 0s
// low + 1 --> mid : 1's
// mid + 1 --> high : Unsorted
// high --> n-1 : 2's


#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& arr) {
    int n = arr.size();
    int low = 0, mid = 0, high = n-1;
    while(mid<=high){
        if(arr[mid]==0)
            swap(arr[low++], arr[mid++]);
        else if(arr[mid] == 1)
            mid++;
        else
            swap(arr[mid], arr[high--]);
    }    
}

int main(){
    
    return 0;
}