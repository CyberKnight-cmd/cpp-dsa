#include<bits/stdc++.h>
using namespace std;


// O(n/2) : Time Complexity
// O(n) : Space Complexity
void rearrange(int arr[], int n){
    vector<int> rearranged(n);
    for(int i = 0, j = n/2, index = 0; i<n/2; i++, j++){
        rearranged[index++] = arr[i];
        rearranged[index++] = arr[j];
    }
    // return rearranged;
    for (auto &&i : rearranged)
        cout << i << " ";
    
}


int main(){
    int n;
    cin >> n;
    int arr[n]; 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    rearrange(arr, n);
    return 0;
}