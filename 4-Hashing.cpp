#include<bits/stdc++.h>
using namespace std;


void numberHashing()
{
    int n, MAX_SIZE = 10;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    
    
    // precompute
    int hash[MAX_SIZE] = {0};
    for(int i = 0; i < n; i++)
        hash[arr[i]] += 1;

    int q, number;
    cin >> q;
    while (q--)
    {
        cin >> number;
        // fetch
        cout << hash[number] << endl;
    }
}


void numberHashingUsingMap() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Precompute frequencies using map
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
        mpp[arr[i]]++;

    // Print all elements and their frequencies
    for (auto it : mpp)
        cout << it.first << " -> " << it.second << endl;

    // Answer queries
    int q, number;
    cin >> q;
    while (q--) {
        cin >> number;
        cout << mpp[number] << endl;  // If not found, returns 0
    }
}


void numberHashingUsingUnorderedMap() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Precompute frequencies using map
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
        mpp[arr[i]]++;

    // Print all elements and their frequencies
    for (auto it : mpp)
        cout << it.first << " -> " << it.second << endl;

    // Answer queries
    int q, number;
    cin >> q;
    while (q--) {
        cin >> number;
        cout << mpp[number] << endl;  // If not found, returns 0
    }
}
// Homework for finding the maximum frequency of a given element
void numberHashingUsingUnorderedMapMAXMIN() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Precompute frequencies using map
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
        mpp[arr[i]]++;

    // Print all elements and their frequencies
    for (auto it : mpp)
        cout << it.first << " -> " << it.second << endl;

    // Find MAX & MIN
    pair<int, int> max = {INT_MIN, INT_MIN};
    pair<int, int> min = {INT_MAX, INT_MAX};

    for (auto it : mpp){
        if(it.second>max.second){
            max.first = it.first;
            max.second = it.second;
        }
        if(it.second<min.second){
            min.first = it.first;
            min.second = it.second;
        }
    }

    // Printing max and min
    printf("Maximum frequency : %d  -> %d \n", max.first, max.second);
    printf("Minimum frequency : %d  -> %d ", min.first, min.second);
    
}


// string methods
void characterHashingLowerCase(string s= "arya"){
    int n = s.size();
    // Pre-compute
    int hash[26] = {0}; // Considering only lowercase characters
    for(int i = 0; i < n; i++)
        hash[int(s[i]) - 97]++;
    
    // fetch, Time Complexity O(Q) --> Q is the number of Queries
    char a;
    int q = 0;
    cin >> q;
    while(q--){
        cin >> a;
        cout << hash[int(a) - 97]<< endl;
    }
}


void characterHashing(string s= "arya"){
    int n = s.size();
    // Pre-compute
    int hash[256] = {0}; // Considering only lowercase characters
    for(int i = 0; i < n; i++)
        hash[s[i]]++;
    
    // fetch, Time Complexity O(Q) --> Q is the number of Queries
    char a;
    int q = 0;
    cin >> q;
    while(q--){
        cin >> a;
        cout << hash[a]<< endl;
    }
}


void characterHashingUsingMap(string s = "arya"){
    int n = s.size();
    map<char,int> mpp;
    // Pre-compute
    for(int i = 0; i < n; i++){
        mpp[s[i]]++;
    }

    for (auto it : mpp)
        cout << it.first << " -> " << it.second << endl;
}

void characterHashingUsingUnorderedMap(string s = "arya"){
    int n = s.size();
    unordered_map<char, int> mpp;
    // Pre-compute
    for(int i = 0; i < n; i++){
        mpp[s[i]]++;
    }
    for(auto it : mpp)
        cout << it.first << "->" << it.second << endl;
}

// Homework for finding the maximum frequency in characters
void characterHashingUsingUnorderedMapMAXMIN(string s = "arya"){
    int n = s.size();
    unordered_map<char, int> mpp;
    // Pre-compute
    for(char ch : s){
        mpp[ch]++;
    }

    // Finding max and min
    int max = INT_MIN, min = INT_MAX;
    char max_element, min_element;
    for(auto it : mpp){
        if(it.second>max){
            max = it.second;
            max_element = it.first;
        }
        if(it.second<min){
            min = it.second;
            min_element = it.first;
        } 
    }
    
    // Printing max and min
    printf("Maximum frequency : %c  -> %d \n", max_element, max);
    printf("Minimum frequency : %c  -> %d ", min_element, min);
}

int main(){
    // numberHashing();
    // characterHashingLowerCase("loremipsumdolorsitametconsecteturadipiscingelitabcdefxyzabcxyzabcdeeeeeeeeeeeeffffgghhiijjkkllllmmmmnnnnooooppqqqrrrrssstttuuuuvvvwwwxxxyyyzzz");
    // characterHashing("Arya123xyzXYZ!@#Arya321");

    // numberHashingUsingMap();
    // characterHashingUsingMap("loremipsumdolorsitametconsecteturadipiscingelitabcdefxyzabcxyzabcdeeeeeeeeeeeeffffgghhiijjkkllllmmmmnnnnooooppqqqrrrrssstttuuuuvvvwwwxxxyyyzzz");

    // numberHashingUsingUnorderedMap(); 
    // characterHashingUsingUnorderedMap("loremipsumdolorsitametconsecteturadipiscingelitabcdefxyzabcxyzabcdeeeeeeeeeeeeffffgghhiijjkkllllmmmmnnnnooooppqqqrrrrssstttuuuuvvvwwwxxxyyyzzz");


    // // Homework
    // characterHashingUsingUnorderedMapMAXMIN("loremipsumdolorsitametconsecteturadipiscingelitabcdefxyzabcxyzabcdeeeeeeeeeeeeffffgghhiijjkkllllmmmmnnnnooooppqqqrrrrssstttuuuuvvvwwwxxxyyyzzz");
    numberHashingUsingUnorderedMapMAXMIN();
    return 0;
}