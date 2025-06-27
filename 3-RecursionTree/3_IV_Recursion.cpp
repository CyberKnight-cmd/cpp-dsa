#include <bits/stdc++.h>
using namespace std;


// Using two pointer and two variables.
void reverseArray(int arr[], int l, int r) {
    if (l >= r) return;         // base case
    
    swap(arr[l], arr[r]);   // swap arr[l] and arr[r]
    reverseArray(arr, l + 1, r - 1);
}


// Using two pointer and one variable.
void reverseArray(int n, int arr[], int i){
    if(i>=n/2) return;
    swap(arr[i], arr[n-i-1]);
    reverseArray(n, arr, i+1);
}


bool isPalindrome(string a, int len, int i){
    if(i >= len/2) return true;
    if(a[i] != a[len-i-1]) return false;
    return isPalindrome(a, len, i+1);
    
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    // reverseArray(arr, 0, n - 1);  // use indices 0 to n-1
    reverseArray(n, arr, 0);  // starts from 0
    // print to verify
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;


    // For Palindrome.
    string s;
    cin >> s;
    cout << isPalindrome(s, s.size(), 0);
    return 0;


    // T.C. : O(n/2)
    // S.C : O(n/2)
}
