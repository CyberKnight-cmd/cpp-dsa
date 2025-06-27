#include<bits/stdc++.h>
using namespace std;


int fibo(int n){
    if (n<=1)
        return n;
    return fibo(n-1) + fibo(n-2);
}

void generateSequence(int n, int c = 0){
    if(c==n) return;
    cout << fibo(c) << " ";
    generateSequence(n, c+1);
}

int main(){
    generateSequence(5);
    return 0;
}