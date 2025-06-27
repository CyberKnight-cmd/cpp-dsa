/*
Fibonacci Number

The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

 

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

Constraints:

0 <= n <= 30

Link : https://leetcode.com/problems/fibonacci-number/description/
*/

#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O(2^n)
// Space Complexity : O(1)
int fib(int n){
    if (n<=1)    return n;
    else if(n==1)    return 1;
    else return (fib(n-1) + fib(n-2));
}

// Since this was a recursion problem, I am not implementing any Optimal solution. If you revisit, kindly implement an O(n), O(1) optimal version (prettyyyyy pleaseeeeee) 

int main(){
    int num;
    cin >> num;
    cout << fib(num);
    return 0;
}