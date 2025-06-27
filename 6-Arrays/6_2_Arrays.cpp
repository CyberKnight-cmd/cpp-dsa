#include<bits/stdc++.h>
using namespace std;


void printArray(int arr[], int n, string s = ""){
    cout << endl << s;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}


void swapp(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


// Don't use this as this less memory efficient (3x operations per swap)
// void rotateLeftByOnePlace(int arr[], int n){
//     for(int i = 0; i < n-1; i++`)
//         swapp(arr,i,i+1);
// }


// Rotate left by one place
void rotateLeftByOne(int arr[], int n){
    int temp = arr[0];
    for(int i = 1; i < n; i++)
        arr[i-1] = arr[i];
    arr[n-1] = temp;
}

// Brute Force
void rotateLeftBrute(int arr[], int n, int d){
    d%=n;
    int temp[d];
    for(int i = 0; i < d; i++)
        temp[i] = arr[i];

    for(int i = d; i < n; i++)
        arr[i-d] = arr[i];

    for (int i = n-d; i < n; i++)
        arr[i] = temp[i-(n-d)];
    
}



void rotateLeftOptimal(int arr[], int n, int d){
    reverse(arr,arr + d);
    reverse(arr+d, arr+n);
    reverse(arr,arr+n);
}

/*
reverse(a,b) -> a,b should be two pointers and reverse from <algorithm> reverses all the elements between these addresses

Note : a is inclusive, b is exclusive (bth position will be untouched)

It works internally like this : 

void reverse(int* start, int* end) {
    end--;  // move to last valid element (since end is exclusive)
    while(start < end){
        std::swap(*start, *end);
        start++;
        end--;
    }
}

*/


// Assignment : Write for rotateRight by one place and by D place.


void moveZeroesBrute(int arr[], int n){
    vector<int> temp;
    // T.C : O(n)
    for (int i = 0; i < n; i++)
        if(arr[i])
            temp.push_back(arr[i]);
    // T.C. : O(n-x) where x--> non-negative numbers
    for(int i = 0; i < temp.size(); i++){
        arr[i] = temp[i];
    }
    // T.C. : O(x) where x--> non-negative numbers
    for(int i = temp.size(); i < n; i++){
        arr[i] = 0;
    }
    // Total Time complexity : O(n + n - x + x) --> O(2n)
    // Total Space Complexity : O(x)
}

void moveZeroesOptimal(int arr[], int n) // Two Pointers : J and I
{
    int j = -1;
    // O(x)
    for(int i = 0; i < n; i++)
        if(!arr[i]){
            j = i;// j goes to first occuring zero
            break;
        }
    if(j==-1) return; // early exit if no zero found
    
    // O(n-x)
    for(int i = j+1; i < n; i++){
        if(arr[i]) // true on first occurence of non-zero number
            swapp(arr, i, j++);// j is incremented after the swap
    }

    // Total time complexity : O(x + n - x) --> O(n)
    // Total time complexity : O(1)
}

int linearSearch(int arr[], int n, int searchElement){
    for(int i = 0; i < n; i++){
        if(arr[i] == searchElement)
            return i;// returns first index
    }
    return -1;
}

// Assignment : Do it for all Occurences using a vector


 
void unionOfTwoSortedArraysBrute(int arr1[], int n, int arr2[],  int m){
    set<int> st;
    // O(nlogn)
    for(int i = 0; i < n; i++)
        st.insert(arr1[i]);
    // O(mlogm)
    for(int i = 0; i < m; i++)
        st.insert(arr2[i]);
    //O(n+m)
    int uni[st.size()], index = 0;
    for(int it : st){
        uni[index++] = it;
        cout << it << " ";
    }

    // Total Time Complexity : O(nlogn + mlogm) + O(n+m)
    // Total Space Complexity : O(n+m) + O(n+m)
} 

void unionOfTwoSortedArraysOptimal(int arr1[], int n, int arr2[],  int m){
    int i = 0, j = 0;
    vector<int> unionArr;

    while(i<n && j<m){
        if(arr1[i] <= arr2[j]){
            if(unionArr.size() == 0 || unionArr.back()!=arr1[i])    unionArr.push_back(arr1[i]);
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back()!=arr2[j])    unionArr.push_back(arr2[j]);
            j++;
        }
    }

    while(i<n){
        if(unionArr.back()!=arr1[i]) unionArr.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        if(unionArr.back()!=arr2[j]) unionArr.push_back(arr2[j]);
        j++;
    }

    for (auto it : unionArr)
        cout << it << " ";

    // Total Time Complexity : O(n+m)
    // Total Space Complexity : O(n+m)
}


vector<int> intersectionOfTwoArrayBrute(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    vector<int> Intersection;
    if(n<m){
        int visitedArray[n] = {0};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(arr2[i] == arr1[j] && !visitedArray[j]){
                    Intersection.push_back(arr2[i]);
                    visitedArray[j] = 1;
                    break;
                }
                if(arr1[j] > arr2[i]) break;
            }
        }
    }
    else{
        int visitedArray[m] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr1[i]==arr2[j]&& !visitedArray[j]){
                    Intersection.push_back(arr1[i]);
                    visitedArray[j] = 1;
                    break;
                }
                if(arr2[j] > arr1[i]) break;
            }
        }
    }
    return Intersection;
}


vector<int> intersectionOfTwoArrayOptimal(vector<int> &arr1, vector<int> &arr2){
    
    vector<int> intersection;
    int i = 0, j = 0;
    int n = arr1.size(), m = arr2.size();
    while (i<n && j<m)
    {
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    

    return intersection;
}

int main(){
    // int n, d;
    // cin >> n >> d;

    // int arr[n];
    // for(int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }

    // rotateLeftBrute(arr, n, d);
    // rotateLeftOptimal(arr,n,d);
    // printArray(arr,n, "After rotating : ");

    // moveZeroesBrute(arr, n);
    // moveZeroesOptimal(arr, n);
    // printArray(arr, n, "After Swapping : ");

    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for(int i = 0; i < n; i++)
        cin >> arr1[i];

    for(int i = 0; i < m; i++)
        cin >> arr2[i];
    // unionOfTwoSortedArraysBrute(arr1, n, arr2, m);
    unionOfTwoSortedArraysOptimal(arr1, n, arr2, m);
    return 0;
}