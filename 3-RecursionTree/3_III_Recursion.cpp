#include<bits/stdc++.h>
using namespace std;

//Parameterised Method
void sumOfNumbers(int i, int sum){
    if (i<1)
    {
        cout << sum;
        return;
    }
    sumOfNumbers(i-1, sum + i);
}

// Non-parameterised
int sumOfNumbers(int i){
    if(i>0) return (i + sumOfNumbers(i-1));
    return 0;
}


// Parameterised
void factorial(int c, int i){
    if (i==0){
        cout << c;
        return;
    }
    factorial (c*i, i - 1);
}


// Non-Parameterised
int factorial(int i){
    if(i==0) return 1;
    else return i*factorial(i-1);
}
int main(){
    sumOfNumbers(5,0);
    cout << endl << sumOfNumbers(5);
    return 0;
}