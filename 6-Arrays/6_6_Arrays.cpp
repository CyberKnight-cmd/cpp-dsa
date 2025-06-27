#include<bits/stdc++.h>
using namespace std;


void printArray(int arr[], int n, string s = ""){
    cout << endl << s;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}


void mergeParts(int arr[], int low, int mid, int high){
    int left = low, right = mid+1, index = 0;
    int temp[high - low + 1];
    
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right])
            temp[index++] = arr[left++];
        else
            temp[index++] = arr[right++];
    }

    while(left<=mid){
        temp[index++] = arr[left++];
    }
    
    while(right<=high){
        temp[index++] = arr[right++];
    }

    for (int i = 0; i < index; i++)
        arr[low + i] = temp[i];
}

void mergeSort(int arr[], int low, int high){
    if(low>=high)   return;
    int mid = (low + high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    mergeParts(arr,low,mid,high);
}

void sortAnArrayOfZeroesOnesAndTwoBrute(int arr[], int n){
    // Use sorting
    mergeSort(arr, 0, n-1);
    // T.C. : O(nlogn)
    // S.c. : O(n)
}

void sortAnArrayOfZeroesOnesAndTwoBetter(int arr[], int n){
    int cnt0 = 0, cnt1 = 1, cnt2 = 2;
    for(int i = 0; i < n; i++){
        if(!arr[i]) cnt0++;
        else if(arr[i]==1) cnt1++;
        else cnt2++;
    }
        for(int i = 0; i < cnt0; i++)
            arr[i] = 0;
        for(int i = cnt0; i < cnt0+cnt1; i++)
            arr[i] = 1;
        for(int i = cnt0+cnt1; i < cnt0+cnt1+cnt2; i++)
            arr[i] = 2;
}

void sortAnArrayOfZeroesOnesAndTwoOptimal(int arr[], int n){
    int low = 0, mid = 0, high = n - 1;
    while (mid<=high)
    {
        if(arr[mid] == 0)   swap(arr[mid++],arr[low++]);
        else if(arr[mid] == 1)   mid++;
        else swap(arr[mid],arr[high--]);
    }
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    printArray(arr,n,"Before Sorting : ");
    // sortAnArrayOfZeroesOnesAndTwoBrute(arr,n);
    sortAnArrayOfZeroesOnesAndTwoBetter(arr,n);
    printArray(arr,n,"After Sorting : ");
    return 0;
}