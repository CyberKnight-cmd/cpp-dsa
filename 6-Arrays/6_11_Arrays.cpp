#include<bits/stdc++.h>
using namespace std;

void rev(int *start, int *end){
    end--;
    while(start<end){
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void swapp(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void nextPermutationOptimal(int arr[], int n){
    
    // Finding the breakpoint
    int breakPoint = -1;
    for(int i = n-2; i >= 0; i--)
        if(arr[i] < arr[i+1]){
            breakPoint = i;
            break;
        }
    
    // Checking the edge case
    if (breakPoint==-1){
        rev(arr,arr+n);
        return;
    }

    // Swapping the breakpoint
    for(int i = n-1; i > breakPoint; i--)
        if(arr[i]>arr[breakPoint]){
            swapp(arr+i, arr+breakPoint);
            break;
        }

    // Reversing the rest(to get them in ascending order)
    rev(arr+breakPoint+1, arr+n);
}

    

int main(){
    int n;
    cin >> n;
    int arr[n]; 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    nextPermutationOptimal(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}