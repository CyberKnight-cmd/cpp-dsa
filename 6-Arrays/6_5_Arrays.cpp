#include<bits/stdc++.h>
using namespace std;

int placePivot(int arr[], int low, int high){
    int pivot = arr[low], left = low, right = high;{
        while (left<right)
        {
            while(arr[left]<=pivot && left<=high)   left++;
            while(arr[right]>pivot && right>=low)   right--;

            if(left<right) swap(arr[left], arr[right]);
        }
        swap(arr[low], arr[right]);
        return right;
    }
}

void quickSort(int arr[], int low, int high){
    if(low>=high)
        return;
    int pIndex = placePivot(arr, low, high);
    quickSort(arr, low, pIndex-1);
    quickSort(arr,pIndex+1,high);
}



bool isTwoSumPresentBrute(int arr[], int n, int target){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[i] + arr[j] == target)
                return true;
        }
    }
    return false;
}

vector<pair<int, int>> allTwoSumsBrute(int arr[], int n, int target) {
    vector<pair<int, int>> indexes;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                indexes.push_back({i, j});
            }
        }
    }
    return indexes;
}

bool isTwoSumPresentBetter(int arr[], int n, int target){
    map<int,int> elementHash;
    for(int i = 0; i < n; i++){
        int requiredValue = target - arr[i];
        if(elementHash.size() != 0 && elementHash.find(requiredValue) != elementHash.end())
            return true;
        
        elementHash[arr[i]] = i;
    }
    return false;
}


vector<pair<int, int>> allTwoSumsBetter(int arr[], int n, int target){
    vector<pair<int, int>> indexes;
    unordered_map<int, int> elementHash;
    for(int i = 0; i < n; i++){
        int requiredValue = target - arr[i];
        if(elementHash.find(requiredValue) != elementHash.end())
            indexes.push_back({elementHash[requiredValue], i});
        
        if(elementHash.find(requiredValue) == elementHash.end())
            elementHash[arr[i]] = i;
    }
    return indexes;
}


bool isTwoSumsPresentOptimal(int arr[], int n, int target){
    quickSort(arr,0, n-1);
    int left = 0, right = n-1, sum = 0;
    while(left<right){
        sum = arr[left] + arr[right];
        if(sum<target){
            left++;
        }
        else if(sum>target){
            right--;
        }
        else
            return true;
    }
    return false;
    // Time Complexity : O(nlogn) + O(n)
    // Space Complexity : O(1)
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // vector<pair<int, int>> indexes = allTwoSumsBrute(arr, n, 21);

    // for (auto &it : indexes)
    //     cout << it.first << ", " << it.second << " --> " << arr[it.first] << " + " << arr[it.second] << endl;
    
    // cout << boolalpha << isTwoSumPresentBetter(arr, n, 21);
    // vector<pair<int, int>> indexes = allTwoSumsBetter(arr, n, 21);

    // for (auto &it : indexes)
    //     cout << it.first << ", " << it.second << " --> " << arr[it.first] << " + " << arr[it.second] << endl;
    cout << boolalpha << isTwoSumsPresentOptimal(arr, n, 21);
    return 0;
}