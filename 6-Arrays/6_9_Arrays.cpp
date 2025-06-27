#include<bits/stdc++.h>
using namespace std;

int buyAndSellStock(int arr[], int n){
    int minimalCostforBuying = arr[0], profit = 0;

    for(int i = 1; i < n; i++){
        int cost = arr[i] - minimalCostforBuying;      // potential profit if bought at min and sold today
        profit = max(profit, cost);                    // update maximum profit so far
        minimalCostforBuying = min(minimalCostforBuying, arr[i]);  // update min buying cost
    }

    cout << profit;
    return profit;
}
int main(){
    
    return 0;
}