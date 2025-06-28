#include<bits/stdc++.h>
using namespace std;

// Brute force solution
// O(2n) : Time Complexity
// O(n) : Space Complexity
void rearrangeBrute(int arr[], int n){
    int positive[n/2], negative[n/2];
    int positiveIndex = 0, negativeIndex = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]>=0)   
            positive[positiveIndex++] = arr[i];
        else
            negative[negativeIndex++] = arr[i];
    }
    
    for (int i = n-1; i <= 0; i++)
    {
        if(i%2 == 0)
            arr[i] = positive[--positiveIndex];
        else
            arr[i] = negative[--negativeIndex];
    }
    
}


// O(n) : Time Complexity
// O(n) : Space Complexity
void rearrangeOptimal(int arr[], int n){
    int newArr[n];
    int positiveIndex = 0, negativeIndex = 1;
    for(int i = 0; i < n; i++){
        if(arr[i]>=0){
            newArr[positiveIndex] = arr[i];
            positiveIndex += 2;
        }
        else{
            newArr[negativeIndex] = arr[i];
            negativeIndex += 2;
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << newArr[i] << " ";
    }

}


// Number of Positives and negatives are not same.
// Fallback to the brute force method
void rearrangeAlternateOptimal(int arr[], int n){
    vector<int> positive, negative;
    
    for(int i = 0; i<n;i++){
        if(arr[i]<0)    negative.push_back(arr[i]);
        else            positive.push_back(arr[i]);
    }

    for(int positiveIndex = 0, negativeIndex = 0, i = 0;i<n;){
        if(positiveIndex<positive.size())
            arr[i++] = positive[positiveIndex++];
        if(negativeIndex<negative.size())
            arr[i++] = negative[negativeIndex++];
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n]; 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    rearrangeOptimal(arr, n);
    cout << endl;
    rearrangeAlternateOptimal(arr, n);
    return 0;
}