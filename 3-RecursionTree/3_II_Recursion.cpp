#include<bits/stdc++.h>
using namespace std;

//Print name 5 times using Recursion
// Time complexity : O(5)
// Space Complexity : Stack Space (also O(5))
void printName(string name, int n){
    if (n<5){
        cout << name << endl;
        printName(name, n+1);
    }
    else
        return;
}

// General Fashion c to n
// TC : O(n-c)
// SC : O(n-c)
void printNum(int c, int n){
    if(c>n){
        cout << endl;
        return;
    }
        cout << c << " ";
        printNum(c+1, n);
}
// Back Tracking 1 to N
void printNumBacktracking(int c, int n){
    if(c < 1)
        return;
    cout<< n - c + 1 << " ";
    printNumBacktracking(c-1, n);
    
}

// General Fashion c to n
// TC : O(n)
// SC : O(n)
void printNumReversed(int n){
    if (n<1){
        cout << endl;
        return;
    }
    cout << n << " ";
    printNumReversed(n-1);
}

void printNumReversedBacktracking(int c, int n){
    
}

int main(){
    printName("Arya", 0);
    printNum(1, 5);
    printNumReversed(5);
    printNumBacktracking(3,3);
    return 0;
}