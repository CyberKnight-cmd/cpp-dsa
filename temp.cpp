#include<bits/stdc++.h>

int HCF(int x, int y){
    return (y) ? HCF(y, x%y) : x;
}

void HCF_List(const std :: vector<int>& arr){
    int res = arr[0];
    for(size_t i = 1; i < arr.size(); i++){
        if (res==1) break;
        res = HCF(res, arr[i]);
    }
    std :: cout << "HCF : " << res << std :: endl;
}

// Function with default parameter
void greet(std :: string name = "Guest") {
    std :: cout << "Hello, " << name << "!\n";
}

// Overload (different signature)
void greet() {
    std :: cout << "Hi there!\n";
}

int main(){
    int n;
    std :: cin >> n;

    std :: vector<int> arr(n);
    for (int& num : arr)
        std :: cin >> num;
    
    HCF_List(arr);

    // greet();
    return 0;
}