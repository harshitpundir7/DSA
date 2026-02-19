#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void quickSort(vector<int>& arr, int low , int high){
        if(low<high){
            int pivotIndex = partition(arr, low, high);

            quickSort(arr, low, pivotIndex-1);

            quickSort(arr, pivotIndex+1, high);
        }
    }
    int partition(vector<int>& arr, int low , int high){
        int pivot = arr[high];
        int i= low-1;
        for(int j=low ; j<high; j++){
            if(arr[j]<=pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[high]);
        return i+1;
    }
};

int main(){
    int n;
    cout<<"Size of the Array: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    Solution sol;
    sol.quickSort(arr, 0, arr.size()-1);
    for(int x: arr){
        cout<<x<<" ";
    }

    return 0;
}