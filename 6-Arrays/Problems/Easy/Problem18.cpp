#include<bits/stdc++.h>
using namespace std;


int majorityElement(vector<int>& nums) {
// Moore's Voting Algorithm
    int n = nums.size(), number, count = 0;
    for(int i = 0; i < n; i++){
        if(count==0) number = nums[i];

        if(number!=nums[i])
            count--;
        else count++;
    }

    // Verifying
    count = 0;
    for(int i = 0; i < n; i++){
        if(nums[i]==number)
            count++;
    }
    if(count>n/2)   return number;
    else return -1;
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << majorityElement(arr);
    return 0;
}