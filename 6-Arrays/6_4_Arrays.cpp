#include <bits/stdc++.h>
using namespace std;


// Optimal for negative
int largestSubArrayBetter(vector<int> &arr, long long k)
{
    int n = arr.size(), maxLen = 0;
    map<long long, int> indexHash; // prefix sum -> first index
    long long s = 0;

    for (int i = 0; i < n; i++)
    {
        s += arr[i];

        // Case 1: Entire subarray from 0 to i has sum k
        if (s == k)
            maxLen = i + 1;

        // Case 2: Check if there's a previous prefix sum equal to s - k
        // C++ maps don't return nullptr or false — they return a special iterator .end() when a key is missing.
        if (indexHash.find(s - k) != indexHash.end())
        {
            int len = i - indexHash[s - k];
            maxLen = max(maxLen, len);
        }

        // Store the first occurrence of prefix sum
        if (indexHash.find(s) == indexHash.end())
            indexHash[s] = i;
    }

    return maxLen;
}

// Sliding window approach
// Optimal only for positive element
int largestSubArrayOptimal(vector<int> &arr, long long k){
    int j = 0, sum = 0;
    int maxLen = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
        while(sum>k && j<=i)
            sum-=arr[j++];
        if(sum==k)  maxLen = max(maxLen, i- j+ 1);
          
    }
    return maxLen;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << largestSubArrayBetter(arr, 3)<<endl;
    cout << largestSubArrayOptimal(arr, 3);
    return 0;
}