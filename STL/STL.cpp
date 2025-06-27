#include<bits/stdc++.h>
using namespace std;


void explainPair(){
    pair <int,int> p1 = {1,3};
    cout << p1.first << " " << p1.second << endl;

    pair<int, pair<int,int>> p2 = {1, {3,4}};
    cout << p2.first << " " << p2.second.second << " " << p2.second.first << endl;

    pair<int ,int> arr[] = {{1,2}, {2,5}, {5,1}};
    cout << arr[1].second << endl;
}

void explainVector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>>vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int> a(5); // Initializes with a size of 5 all containin 0
    vector<int> ab(5,100); // Initializes with a size of 5 all containin 100

    vector<int> ab_copy(ab); //Copies ab

    // irerator
    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << " ";

    it += 2;
    cout << *(it) << " ";


    vector<int>::iterator it = v.end();
    vector<int>::iterator it = ab.rend();
    vector<int>::iterator it = ab_copy.rbegin();
}

int main(){
    explainPair();
    return 0;
}