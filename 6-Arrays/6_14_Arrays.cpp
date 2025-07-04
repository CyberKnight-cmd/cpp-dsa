#include<bits/stdc++.h>
using namespace std;

void makeZeroes(vector<vector<int>> &arr, int n){
    
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>arr;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            cout << arr[i][j] << " ";
        }
    }
    return 0;
}