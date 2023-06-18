#include<bits/stdc++.h>
using namespace std;

bool subSetForKM(vector<int> &arr, int k, int i, vector<vector<int>> &dp){
    if(k == 0)  return true;
    if(i == 0)  return k == arr[i];

    if(dp[i][k] != -1)  return dp[i][k];
//not Taking the element 
    bool notTake = subSetForKM(arr,k,i-1,dp); 

//Taking the element 
    bool take = false;
    if(k >= arr[i]) take = subSetForKM(arr, k-arr[i],i-1,dp);

    return dp[i][k] = (take || notTake);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    cout<<subSetForKM(arr,k,n-1,dp);
    return 0;
}