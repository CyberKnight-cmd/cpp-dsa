#include<bits/stdc++.h>
using namespace std;


vector<int> leadersInAnArrayOptimal(int arr[], int n){
    vector<int> leaders;
    int max = INT_MIN;
    for(int i = n-1; i >= 0; i--){
        if(max<arr[i]){
            max = arr[i];
            leaders.push_back(arr[i]); 
        }
    }
    // Clever usage of "," operator can be done here like this : 
    // return reverse(leaders.begin(), leaders.end()), leaders;
    reverse(leaders.begin(), leaders.end()); // in the order of the array
    // if asked then sort it
    return leaders;
    
}

int main(){
    int n;
    cin >> n;
    int arr[n]; 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> leaders = leadersInAnArrayOptimal(arr, n);
    for (auto &&i : leaders)
        cout << i << " ";   
    return 0;
}