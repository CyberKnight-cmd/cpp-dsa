#include<bits/stdc++.h>
using namespace std;



int cnt = 0;
void print(){
    if (cnt==4)
        return;
    cout << cnt++ << endl;
    print();
}

int main(){
    print();
    return 0;
}