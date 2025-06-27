/*

### Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
#include <bits/stdc++.h>
using namespace std;



// O(2n) : Time Complexity 
// O(n)  : Space Complexity
//  String Pre-Processing approach
bool isPalindromeBrute(string s)
{
    string newS;
    for (char ch : s)
    {
        if (ch >= 'A' && ch <= 'Z') newS += ch + 32;
        else if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) newS += ch;
    }
    int n = newS.size();
    for (int l = 0, r = n - 1; l < r; l++, r--)
    {
        if (newS[l] != newS[r])
            return false;
    }
    return true;
}


//  O(n) : Time-complexity
//  O(1) : Space-complexity
// Two-pointer in-place approach
bool isPalindromeOptimal(string s){
    if (s.length() > 2e5) return false;
    for(int left = 0, right = s.length() - 1; left<right; left++,right--){
        // Making sure left points to an alphanumeric character
        while (left < right && !isalnum(s[left])) left++;
        // Making sure right points to an alphanumeric character
        while(left< right && !isalnum(s[right])) right--;
        // Checking if they are equal(but they should be lowercase)
        if(tolower(s[left]) != tolower(s[right])) return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    return 0;
    isPalindromeBrute(s);
    isPalindromeOptimal(s);
}
// class Solution {
// public:

// };