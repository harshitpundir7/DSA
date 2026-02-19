#include<bits/stdc++.h>
using namespace std;

void printS(int index, vector<int> ds, int s, int sum, int arr[], int n){
    if(index == n){
        if(s==sum){
            for(auto it: ds) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[index]);
    s+=arr[index];
    printS(index+1, ds, s, sum, arr, n);
    
    s-=arr[index];
    ds.pop_back();

    printS(index+1, ds, s, sum, arr, n);
}

// Print only One
bool printSO(int index, vector<int> ds, int s, int sum, int arr[], int n){
    if(index == n){
        if(s==sum){
            for(auto it: ds) cout<<it<<" ";
            return true;
        }
        return false;
    }
    ds.push_back(arr[index]);
    s+=arr[index];
    if(printSO(index+1, ds, s, sum, arr, n) == true ) return true;
    
    s-=arr[index];
    ds.pop_back();

    if(printSO(index+1, ds, s, sum, arr, n)== true) return true;

    return false;
}

//Number of subset

int printSN(int index, vector<int> ds, int s, int sum, int arr[], int n){
    if(index == n){
        if(s==sum){
          return 1;
        }
        return 0;
    }
    ds.push_back(arr[index]);
    s+=arr[index];
    int l = printSN(index+1, ds, s, sum, arr, n);
    
    s-=arr[index];
    ds.pop_back();

    int r = printSN(index+1, ds, s, sum, arr, n);

    return l+r;
}



int main(){
    int n;
    cout<<"Size of the Array: ";
    cin>>n;
    int arr[n];
    cout<<"Write Elements Of array ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum;
    cout<<"Write the Sum Value";
    cin>>sum;
    vector<int> ds;
    printS(0, ds, 0, sum, arr, n);
    cout<<endl;
    cout<<endl;
    printSO(0, ds, 0, sum, arr, n);
    cout<<endl;
    cout<<endl;
    cout<<printSN(0, ds, 0, sum, arr, n);
    
    return 0;
}