/*
*Shuffle the Array*
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

 

Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
Example 2:

Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]
Example 3:

Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]
 

Constraints:

1 <= n <= 500
nums.length == 2n
1 <= nums[i] <= 10^3
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> shuffleBrute(vector<int> &nums, int n){
    int left = 0, right = n;
    vector<int> shuffledArray(2*n);
    for(int i = 0; i < 2*n; i++){
        if(!(i%2))  shuffledArray[i] = nums[left++];
        else        shuffledArray[i] = nums[right++];
    }
    return shuffledArray;
}


// Learn encoding first.
vector<int> shuffleBetter(vector<int> &nums, int n){
    int number = 1001;
    for(int i = 0; i < n; i++)
        nums[i] += nums[i+1]*number;
    
    
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    return 0;
}