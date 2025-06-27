#include<bits/stdc++.h>
using namespace std;

// Given the number n, return the number of digits
int countDigits(int n){
    // int count = 0;
    // while (n!=0)
    // {
    //     count++;
    //     n/=10;
    // }

    int count = (int) log10(n) + 1; // new method.
    return count;
}

// WAP to generate the reverse of a given number N. Print the corresponding reverse number.
int reverse(int n){
    int rev = 0;
    while (n!=0)
    {
        rev = rev*10 + n%10;
        n/=10;
    }
    return rev;
}


//WAP to determine if a given number is palindrome or not. Print true if it is palindrome. Print false if otherwise.
bool isPalindrome(int n){
    int numCopy = n, rev = 0;
    while (numCopy!=0)
    {
        rev = rev*10 + numCopy%10;
        numCopy/=10;
    }
    return n==rev;
}



// WAP to determine whether a given number is an Armstrong number.
bool isArmstrong(int n){
    int nCopy = n, sum = 0;
    while (nCopy!=0)
    {
        sum += pow(nCopy%10, 3);
        nCopy /= 10;
    }
    return sum==n;    
}

// Print all divisors
void factors(int n){ 
    // for(int i = 1; i < n; i++){
    //     if (n%i==0)
    //         std :: cout << i << " ";
    // }
    vector<int> ls;
    // O(sqrt(n))
    for(int i = 1; i*i < n + 1; i++){
        if (n%i==0)
        {
            ls.push_back(i);
            if (n/i != i)
                ls.push_back(n/i);            
        }
        
    }
    // O(nlog(n))
    sort(ls.begin(), ls.end());
    // O(number of factors)
    for(auto it : ls) cout << it << " ";

    // O(number of factors + nlog(n) + sqrt(n))
}

//Check for prime
bool isPrime(int n){
    int count = 0;
    for(int i = 1; i*i < n + 1; i++){
        if (n%i==0)
        {
            count++;
            if (n/i == i) count++;
        }
    }
    
    return (count==2);
}

// Time complexity : (fast: O(log min(a,b)))
int GCD(int a, int b){
    // Euclidean algorithm
    // gcd (a,b) = gcd(a-b, b)
    // OR gcd (a,b) = gcd(a%b, b
     
    while(a&&b)
        (a>b) ? a%=b : b%=a;
    
    return (a == 0) ? b : a;


}

int main(){
    int n;
    scanf("%d", &n);

    // std :: cout << countDigits(n);
    // std :: cout << reverse(n);
    factors(n);
    return 0;
}